use std::collections::HashMap;

pub struct Solution;
impl Solution {
    #[allow(unused)]
    pub fn evaluate(expression: String) -> i32 {
        parse(&expression).evaluate(&mut Env::new())
    }
}
/// 一个变量和值的Binding
type Bindings = HashMap<String, i32>;

/// 记录变量绑定的环境
struct Env(Vec<Bindings>);

/// 实现一些栈操作
impl Env {
    /// 创建一个空栈
    fn new() -> Self {
        Env(Vec::new())
    }

    /// 从后向前逐帧查找一个变量
    fn find(&self, name: &str) -> Option<i32> {
        self.0.iter().rev().find_map(|map| map.get(name).copied())
    }

    /// 给栈增加新的帧
    fn add_frame(&mut self) {
        self.0.push(HashMap::new());
    }

    /// 从栈顶弹出一个帧
    fn pop(&mut self) -> Option<Bindings> {
        self.0.pop()
    }

    /// 向栈中当前帧添加一个变量
    fn insert(&mut self, k: String, v: i32) {
        self.0.last_mut().and_then(|bindings| bindings.insert(k, v));
    }
}

/// 语法树
#[derive(Debug)]
enum Expr {
    // List, Lisp的基本结构
    List(Vec<Expr>),
    // 数值
    Num(i32),
    // 符号
    Sym(String),
}

use Expr::*;

impl Expr {
    /// 表达式求值
    fn evaluate(&self, env: &mut Env) -> i32 {
        match self {
            // 对于数值，值即为它本身
            Num(n) => *n,
            // 对于符号，在栈中寻找对应的变量
            Sym(s) => env.find(s).unwrap(),
            // 对于列表，调用eval_list函数对其求值
            List(l) => Self::eval_list(l, env),
        }
    }

    /// 列表求值
    fn eval_list(list: &[Expr], env: &mut Env) -> i32 {
        // 对 let form 求值
        let eval_let = |l: &[Expr], env: &mut Env| {
            // 向栈中添加新帧
            env.add_frame();

            // 变量和值成对，单出来的是最终需要求值的表达式
            // 这syntax真烂啊
            let pairs = l.chunks_exact(2);
            let tail_expr = &pairs.remainder()[0];

            // 对于每对变量和值，对值表达式求值后加入环境
            pairs.for_each(|pair| {
                if let [Sym(s), v] = pair {
                    let val = v.evaluate(env);
                    env.insert(s.clone(), val);
                }
            });

            // 对tail求值
            let val = tail_expr.evaluate(env);

            // **离开let，从栈中pop出当前帧**
            env.pop();
            val
        };

        match list {
            // let form，调用eval_let
            [Sym(s), l @ ..] if s == "let" => eval_let(l, env),
            // add func，求值后求和
            [Sym(s), a, b] if s == "add" => a.evaluate(env) + b.evaluate(env),
            // mul func，求值后求积
            [Sym(s), a, b] if s == "mult" => a.evaluate(env) * b.evaluate(env),
            _ => unreachable!(),
        }
    }
}

/// 解析S表达式为语法树
fn parse(expr: &str) -> Expr {
    // 解析atom，能parse为数字就算数字……其他情况为符号
    let parse_atom = |atom: String| atom.parse().map_or(Sym(atom.to_string()), |n| Num(n));

    let mut stack = Vec::new();
    let mut list = Vec::new();
    let mut atom = String::new();

    for c in expr.chars() {
        match c {
            // 新的子表达式开始
            '(' => {
                // 将当前list暂存入stack
                stack.push(list);
                // 并新建一个stack
                list = Vec::new();
            }
            ' ' => {
                if !atom.is_empty() {
                    list.push(parse_atom(atom));
                    atom = String::new();
                }
            }
            // 当前表达式结束
            ')' => {
                // 若atom非空则将其加入list
                if !atom.is_empty() {
                    list.push(parse_atom(atom));
                    atom = String::new();
                }
                // 把当前的list作为元素加入上一层list
                let mut last_list = stack.pop().unwrap();
                last_list.push(List(list));
                // 并返回上一层
                list = last_list;
            }
            // 其他字符作为atom一部分
            _ => atom.push(c),
        }
    }

    if !atom.is_empty() {
        // 只有一个atom的情况
        parse_atom(atom)
    } else {
        // 否则list中唯一的项就是最终结果
        list.pop().unwrap()
    }
}
