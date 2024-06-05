#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : mVec(other.mVec), mDeq(other.mDeq) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        mVec = other.mVec;
        mDeq = other.mDeq;
    }
    return *this;
}

PmergeMe::PmergeMe(int argc, char *argv[])
{
    double num = 0;
    char *end = NULL;

    for (int i = 1; i < argc; ++i)
    {
        num = std::strtod(argv[i], &end);
        if (*end || num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max() || (num - static_cast<int>(num) != 0))
        {
            throw std::runtime_error("Invalid argument");
        }
        mVec.push_back(static_cast<int>(num));
        mDeq.push_back(static_cast<int>(num));
    }
}

void PmergeMe::jacobsthal(unsigned long n)
{
    mJacobsthal.push_back(0);
    mJacobsthal.push_back(1);

    while (mJacobsthal.back() < n)
    {
        mJacobsthal.push_back(mJacobsthal.back() + 2 * mJacobsthal[mJacobsthal.size() - 2]);
    }
}

void PmergeMe::run()
{
    try
    {
        jacobsthal(mVec.size());

        std::cout << "Before: ";
        printVector();

        std::clock_t start_v = std::clock();
        sortVector();
        std::clock_t end_v = std::clock();

        std::clock_t start_d = std::clock();
        sortDeque();
        std::clock_t end_d = std::clock();

        std::cout << "After: ";
        printVector();
        // printDeque();

        // printIsSorted(mVec);

        double time_v = 1000000.0 * (end_v - start_v) / CLOCKS_PER_SEC;
        double time_d = 1000000.0 * (end_d - start_d) / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << mVec.size() << " elements with std::vector : " << time_v << " us" << std::endl;
        std::cout << "Time to process a range of " << mDeq.size() << " elements with std::deque : " << time_d << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void PmergeMe::sortVector()
{
    mergeInsertionSort(mVec);
}

void PmergeMe::sortDeque()
{
    mergeInsertionSortDeq(mDeq);
}

void PmergeMe::printVector()
{
    std::vector<int>::iterator it;
    for (it = mVec.begin(); it != mVec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque()
{
    std::deque<int>::iterator it;
    for (it = mDeq.begin(); it != mDeq.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::mergeInsertionSort(std::vector<int> &vec)
{
    if (vec.size() <= 1)
    {
        return;
    }
    std::vector<int> a;
    std::vector<int> b;
    std::vector< std::pair<int, int> > pairs;
    int mid = vec.size() / 2;

    // Step 1: Pairwise comparison
    for (int i = 0; i < mid; ++i)
    {
        if (vec[i] < vec[mid + i])
        {
            a.push_back(vec[mid + i]);
            b.push_back(vec[i]);
        }
        else
        {
            a.push_back(vec[i]);
            b.push_back(vec[mid + i]);
        }
        // Store mapping
        pairs.push_back(std::make_pair(a.back(), b.back()));
    }
    if (vec.size() % 2)
    {
        b.push_back(vec.back());
    }

    // Step 2: Recursion and Renaming
    this->mergeInsertionSort(a);

    // Permute smaller half
    for (size_t i = 0; i < a.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (a[i] == pairs[j].first)
            {
                b[i] = pairs[j].second;
            }
        }
    }

    // Step 3: Insertion
    std::vector<int> merged;
    merged.reserve(a.size() + b.size());
    if (!b.empty())
    {
        merged.push_back(b[0]);
    }
    merged.insert(merged.end(), a.begin(), a.end());

    // 해당 부분 구현하면서 느낀 점 : 야콥스탈 수가 필요하지 않다. 그냥 이진삽입정렬을 사용하면 된다. 오히려 더 많은 비교를 하게되는 것 같다.
    size_t k = 3;
    // If the size of b is less than the Jacobsthal number, then we can just insert the rest of the elements
    while (mJacobsthal[k - 1] < b.size())
    {
        size_t m;
        mJacobsthal[k] > b.size() ? m = b.size() : m = mJacobsthal[k];
        for (size_t i = m; i > mJacobsthal[k - 1]; --i)
        {
            binaryInsertion(merged, b[i - 1], 0, merged.size());
        }
        ++k;
    }

    vec.clear();
    vec = merged;
}

void PmergeMe::mergeInsertionSortDeq(std::deque<int> &deq)
{
    if (deq.size() <= 1)
    {
        return;
    }
    std::deque<int> a;
    std::deque<int> b;
    std::deque< std::pair<int, int> > pairs;
    int mid = deq.size() / 2;

    // Step 1: Pairwise comparison
    for (int i = 0; i < mid; ++i)
    {
        if (deq[i] < deq[mid + i])
        {
            a.push_back(deq[mid + i]);
            b.push_back(deq[i]);
        }
        else
        {
            a.push_back(deq[i]);
            b.push_back(deq[mid + i]);
        }
        // Store mapping
        pairs.push_back(std::make_pair(a.back(), b.back()));
    }
    if (deq.size() % 2)
    {
        b.push_back(deq.back());
    }

    // Step 2: Recursion and Renaming
    this->mergeInsertionSortDeq(a);

    // Permute smaller half
    for (size_t i = 0; i < a.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (a[i] == pairs[j].first)
            {
                b[i] = pairs[j].second;
            }
        }
    }

    // Step 3: Insertion
    std::deque<int> merged;
    if (!b.empty())
    {
        merged.push_back(b[0]);
    }
    merged.insert(merged.end(), a.begin(), a.end());

    // 해당 부분 구현하면서 느낀 점 : 야콥스탈 수가 필요하지 않다. 그냥 이진삽입정렬을 사용하면 된다. 오히려 더 많은 비교를 하게되는 것 같다.
    size_t k = 3;
    // If the size of b is less than the Jacobsthal number, then we can just insert the rest of the elements
    while (mJacobsthal[k - 1] < b.size())
    {
        size_t m;
        mJacobsthal[k] > b.size() ? m = b.size() : m = mJacobsthal[k];
        for (size_t i = m; i > mJacobsthal[k - 1]; --i)
        {
            binaryInsertionDeq(merged, b[i - 1], 0, merged.size());
        }
        ++k;
    }

    deq.clear();
    deq = merged;
}

void PmergeMe::binaryInsertion(std::vector<int> &vec, int value, int start, int end)
{
    int mid = 0;

    while (start < end)
    {
        mid = (start + end) / 2;

        if (vec[mid] < value)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    vec.insert(vec.begin() + start, value);
}

void PmergeMe::binaryInsertionDeq(std::deque<int> &deq, int value, int start, int end)
{
    int mid = 0;

    while (start < end)
    {
        mid = (start + end) / 2;

        if (deq[mid] < value)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    deq.insert(deq.begin() + start, value);
}

/* just for printing or debugging */
void PmergeMe::printContainer(const std::vector<int> &vec, const std::string &vecName)
{
    std::cout << "[ " << vecName << " ]: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << ">> size(" << vec.size() << ")" << std::endl;
}

void PmergeMe::printContainer(const std::vector< std::pair<int, int> > &vecPair, const std::string &pairName)
{
    std::cout << "[ " << pairName << " ]: ";
    for (size_t i = 0; i < vecPair.size(); ++i)
        std::cout << "(" << vecPair[i].first << ", " << vecPair[i].second << ") ";
    std::cout << ">> size(" << vecPair.size() << ")" << std::endl;
}

void PmergeMe::printIsSorted(const std::vector<int> &vec)
{
    bool flag = true;
    std::vector<int>::const_iterator it;
    for (it = vec.begin() + 1; it != vec.end(); ++it)
    {
        if (*(it - 1) > *it)
        {
            flag = false;
            break;
        }
    }
    std::cout << "[ vector sorted ]: ";
    if (flag == true)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}
