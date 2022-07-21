use std::collections::HashMap;
#[allow(unused)]
struct MagicDictionary {
    root: Node,
}
#[allow(unused)]
struct Node {
    is_end: bool,
    children: HashMap<char, Box<Node>>,
    value: char,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MagicDictionary {
    #[allow(unused)]
    fn new() -> Self {
        MagicDictionary {
            root: Node {
                is_end: false,
                children: HashMap::new(),
                value: '\\',
            },
        }
    }
    #[allow(unused)]
    fn add_string(&mut self, word: &str) {
        let mut cur_node_ref = &mut self.root;
        for (index, character) in word.chars().enumerate() {
            if !cur_node_ref.children.contains_key(&character) {
                let char_node_box = Box::new(Node {
                    is_end: if index == word.chars().count() - 1 {
                        true
                    } else {
                        false
                    },
                    children: HashMap::new(),
                    value: character,
                });
                cur_node_ref.children.insert(character, char_node_box);
            }
            cur_node_ref = cur_node_ref.children.get_mut(&character).unwrap();
            if index == word.chars().count() - 1 {
              cur_node_ref.is_end = true;
            }
        }
    }
    #[allow(unused)]
    fn word_exist(&self, word: &str) -> bool {
        let mut current_node_ref = &self.root;
        for character in word.chars() {
            if !current_node_ref.children.contains_key(&character) {
                return false;
            }
            current_node_ref = current_node_ref.children.get(&character).unwrap();
        }
        if current_node_ref.is_end {
            return true;
        }
        false
    }
    #[allow(unused)]
    fn build_dict(&mut self, dictionary: Vec<String>) {
        for word in &dictionary {
            self.add_string(word);
        }
    }
    #[allow(unused)]
    fn search(&self, search_word: String) -> bool {
        let mut word_index: usize = 0;
        let mut node_ref = &self.root;
        let mut characters = search_word.chars().collect::<Vec<char>>();
        while word_index < search_word.chars().count() {
            let character = characters[word_index];
            // possible change char
            for pairs in &node_ref.children {
                if *(pairs.0) == character {
                    continue;
                }
                characters[word_index] = *pairs.0;
                if self.word_exist(&characters.iter().collect::<String>()) {
                    return true;
                }
                characters[word_index] = character;
            }
            if !node_ref.children.contains_key(&character) {
                return false;
            }
            node_ref = node_ref.children.get(&character).unwrap();
            word_index += 1;
        }
        false
    }
}

#[test]
fn it_works() {
    let mut solve = MagicDictionary::new();
    let  strings: Vec<&str> = vec!["hqcefkkdtxvkokxupqheffemlcettmgmybmcjqd",
    "tqvuevvcqdbyganadubbzprtadbigvcbydwlwppklqqdmewfphkltyfvtlfwdmgfpslozkcmwelqmkrzwoldycmmccewecrwpvs",
    "figvqvkohvkiihihmdqpezubuqdjxenwzzrujkclpcyvdvhrdelhn",
    "fobyndkctmahjpjhiyaalgwovlxettyojlwudhhtdvasfdzypryz",
    "afqfkmxmtoficmaekaldghcbovyqoaajwrognzcsymlmuqiqqcawjklybteamknzpazhokofsfgwxjnindi",
    "hzwykjriueezwmnmyvxafchqicaqnbqrbsqnvmuaarlamzgwbt",
    "opvfxeqrijhxodcocboalfkjswpnxpykcltbucskwqokvabcpnncyxqknqaukwlsyfcymjopy",
    "svndbqiznkpayoqwqfrbkghvywzijxsxguzrzacnxldspwhtyvslyfkrfvxnwfqtwzkbgn",
    "svegroaaeymtrykymumvplqzxwsefkeslfwguaagiffegfsgsjudeocqfejruuyydmrkoemhfpgraslgyrkcfphmhwhrdwrle",
    "iigozeamuhmubqncozsztszzeagyghbwlhzdck",
    "kyqqcc","wbvtywlnkdccmmkmpckergvuruaddvkpmsqrvtitjfzsecp","fo","ylnvlngvebfnng","slpheqzaptkoubtviwnmjhtvfcsreysiuzpylkdnzznlaxutigpptqeqifqjhrftnfns","ykqehgfczn","tcqxjvavirvzukhyhjnwykuzyarrlrmaycxemqhgzemokoypmil","uprqmgudyfefasmbqywvcugdqujijzsuboifgbktbgxswbrlxbiuvbogdqyzfxnvmmifrosruzvdrhtlxfwfzjikvplvwh","memyndggyvsqjdntrgxecgrkmcmrkkfjdasxhgr","lnahczutqyhwumbapructp","motrdfychlrurepgnqvprhunwiwmrhajatpxjjdvdtmtexiwmksvbtdnzqqftrnzqdscpepkyjdsgmeqdztrl","vedyymdprufufokvxwdaoaiidzighghuryoineyycrhdxrdkxdgmaahq","fizycbajzqifsjtrzymoenxrkgsrxgrblmzentdui","jqgzwm","rnxqkwyridhfwlgkdrmgxcoodqnkauplbhuxmmwgocnoumtemebikopkq","maepukvxnieiudrguuvjqefwcpopxezjaxzeaqramwmchbvvpwjmcjaknqbjfxjonjmghpudqcckxmfrxzdjeqmgmitxpc","uvakofoanddmrunpbwyqxhlrdarkohxphvtvckdnmfplpjuxogwsgrwvftyaawlwtftzzmfbeubkpnysyvd","aipwbfwavlkkkicuyvuweojuqsiulnchunbobpohrkujnekegegvylnvgcahckwnurtmxkmutdmikorjmguqxkd","mjzdcybukypmqhqgpjqfr","dxbvdcxvemjkujnpjqfeigejzgkfsowxegbrrlseylxczbxvrzlnymopgyvlzmyannsgxjnvguosgeimauym","zignfufvuereucrzbzhinoqbyegnntsfpgewzrssbgag","evyeskltiibijggujjjmxyetqyfpowpfvauiuzwzfsujmlevgaqzd","tlovkhoxtmxzlnoqzvtyuxekjyolh","dqibutwieciegwazbylekyvhnepwlwrsjcdupiivnfbyudwrcytefrtckzwbvqexdpvjwhqdfjcjhxyfpljyupdjdslstxwzajf","rmuawruoozzgkhavbrfguqukjpqgcrttbcwkwyvfannqkkdwmakjkwynmftcsirrriwuovdmanobrmvafwllihw","lciuhohzmlpknvxcnvutukbhyeqzlopspkopefoacwnfgvdvywuepvbkbxverqwfqmmqelrffdzcojelnhfagbhuiuaqzdokt","ikaczbhltbtvybhuoegdtbfhmelxhcepbiegursieuhjrjvcsjdynpljumxfzvuxzahmnfrvdfwdngcmwzzzcpynjanxffwsjit","kevxuounfbplmpgesdcrsogibccvnxzogntxhzmmnjomadkchlmyhrkwuivcphgrgot","vqbajkmysnlowqgcuqfbfsgidnlrattafbqemcnnbejnykhxxopexfzlqnwlboparbgfajnhjian","mldnittgqyngzcwumffnjkmnwerryligmoihinxrapdjsfwufsleatlxlfrookaivdvxy","ckbaywevzrayotbyugvvlyrptjetekrkudclafrqkzyocndxodmjkyqcwxxicuomppifqhdcoguzzmppn","sbbagyuhzuvywflbirezefxxeo","yyhrkjdngsyfcrqlgkyqcqkchhxqwjspgnrxwubhaetmxfmhwevlefgabozliipxgxxloq","bixqbrljjijkwypdoicofvjavoqyuznapiqwmrxbbvmu","bbuqcrvyyauhyeafjyahheklalhasbohbossoivhyivjknlfi","hxkvflrwafqgjrbnkgbginxusbzzjospayoclavlhupaqghanqvygxahzzyspyued","ybsemhouwzsgoqagiynodiayeaengqedtqobhyupmafjgxnvfdhfrephtaqedjkvjwnfulx","fszdvdripirczluoahwktyozjqyhwllnppjhgyoycunjkuiqldmmpxezsigxmcjveinlqnpjhkxfbhuelhkvrknl","wwactkdvlzzelfmxhycjgbmdzmptrclhxhvdnfjxzuhnoebjcdqktxamshdrqzjhhj","qckjulixfmlezxaompowzzzzammrblsziuwsksjzfoyieeapxkqrxznlxiyiahxosoqauivkygzehhikzi","ytajkptmjwjkbehixuxuioj","bslhokzotyjhgeodrnkd","trg","iyoqrzttwixxrikrm"];
    for str in strings {
        solve.add_string(str);
    }
    assert_eq!(solve.search(String::from("fg")), true);
}
