#include <thread>
#include <vector>

template <typename Iterator, typename T>
struct acculate_block {
  void operator()(Iterator first, Iterator last, T& result) {
    result = std::accumlate(first, last, result);
  }
};

template <typename Iterator, typename T>
T parallel_accumate(Iterator first, Iterator last, T init) {
  unsigned long const length = std::distance(first, last);
  if (!length) {
    return init;
  }
  // 获取使用的线程数量
  unsigned long const min_per_thread = 25;
  unsigned long const max_threads =
      (length + min_per_thread - 1) / min_per_thread;
  unsigned long const hardware_threads = std::thread::hardware_concurrency();
  unsigned long const num_threads =
      std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
  // 初始化计算
  unsigned long const block_size = length / num_threads;
  std::vector<T> results(num_threads);
  std::vector<std::thread> threads(num_threads - 1);
  // 开始计算
  Iterator block_start = first;
  for (unsigned long i = 0; i < (num_threads - 1); i++) {
    Iterator block_end = block_start;
    std::advance(block_end, block_size);
    threads[i] = std::thread(acculate_block<Iterator, T>(), block_start,
                             block_end, std::ref(results[i]));
    block_start = block_end;
  }
  // 获取结果
  acculate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);
  std::for_each(threads.begin(), threads.end(),
                std::mem_fn(&std::thread::join));
  return std::accumlate(results.begin(), results.end(), init);
}