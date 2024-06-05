#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <string>
# include <vector>
# include <deque>

class PmergeMe
{
private:
    std::vector<unsigned long> mJacobsthal;
    std::vector<int> mVec;
    std::deque<int> mDeq;

    void jacobsthal(unsigned long n);

    void sortVector();
    void mergeInsertionSort(std::vector<int> &vec);
    void binaryInsertion(std::vector<int> &vec, int value, int start, int end);
    void printVector();

    void sortDeque();
    void mergeInsertionSortDeq(std::deque<int> &deq);
    void binaryInsertionDeq(std::deque<int> &deq, int value, int start, int end);
    void printDeque();

    void printContainer(const std::vector<int> &vec, const std::string& vecName);
    void printContainer(const std::vector< std::pair<int, int> >& vecPair, const std::string& pairName);
    void printIsSorted(const std::vector<int>& vec);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &other);
    PmergeMe(int argc, char *argv[]);

    void run();
};

#endif
