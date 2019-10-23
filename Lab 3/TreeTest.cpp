#include <iostream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>
#include <algorithm>

void PrintResult(
        bool passed,
        std::string description) {
    std::cout << (passed ? "PASS: " : "FAIL: ")
              << description
              << std::endl;
}

void PrintResult(
        bool passed,
        int number,
        std::string description) {
    std::cout << number
              << (passed ? " PASS: " : " FAIL: ")
              << description
              << std::endl;
}


void DisplayTree(
        BinSearchTree *tree,
        std::string description,
        std::string expected) {
    std::cout << "+++++++++++++++++++++++++" << std::endl;
    std::cout << description << std::endl;
    std::cout << "+++++++++Expected++++++++" << std::endl;
    std::cout << expected;
    std::cout << "+++++++++++++++++++++++++" << std::endl;
    std::cout << "---------Found-----------" << std::endl;
    tree->inorderDump();
    std::cout << "-------------------------" << std::endl;
}


void TestEmptyTree() {
    BinSearchTree *t = new BinSearchTree();
    DisplayTree(t, "expecting no elements printed", "");
    PrintResult(!t->find(1234), "find in empty tree.");
    PrintResult(!t->iterFind(1234), "iterFind in empty tree.");
    PrintResult(t->maxDepth() == 0, "maxDepth expecting 0 elements.");
    PrintResult(t->size() == 0, "size expecting 0 elements.");
    std::cout << std::endl;
    delete t;
}

void TestSmallTree(
        const std::vector<int>& evenNumbers,
        int low,
        int high,
        std::string expectedNumbers,
        int depth) {
    BinSearchTree *t = new BinSearchTree();

    for(auto number : evenNumbers) {
        std::cout << "inserting " << number << std::endl;
        t->insert(number);
    }
    DisplayTree(t, "expecting elements printed", expectedNumbers);

    int treeDepth = t->maxDepth();
    int treeSize = t->size();
    PrintResult(depth == treeDepth, treeDepth, "expecting matching depth");
    PrintResult(treeSize == evenNumbers.size(), treeSize, "expecting matching size");

    for(int number = low; number <= high; number++) {
        bool findResult = t->find(number);
        if (number % 2 == 0) {
            PrintResult(findResult, number, "find in tree.");
        }
        else {
            PrintResult(!findResult, number, "!find in tree.");
        }
    }

    for(int number = low; number <= high; number++) {
        bool findResult = t->iterFind(number);
        if (number % 2 == 0) {
            PrintResult(findResult, number, "iterFind in tree.");
        }
        else {
            PrintResult(!findResult, number, "!iterFind in tree.");
        }
    }

    std::cout << std::endl;

    delete t;
}

std::string MakeExpectation(
        int low,
        int high) {
    std::stringstream s;
    for (int i = low; i <= high; i += 2) {
        s << i << std::endl;
    }
    return s.str();
}

void BalancedInsert(
        BinSearchTree* t,
        int low,
        int high,
        std::vector<int> &microseconds) {
    if (low > high) {
        return;
    }
    int mid = (low + high) / 2;
    auto insertStart = std::chrono::steady_clock::now();
    t->insert(mid);
    auto insertEnd = std::chrono::steady_clock::now();
    auto insertElapsed = std::chrono::duration_cast<std::chrono::microseconds>(insertEnd - insertStart);
    microseconds.push_back(insertElapsed.count());
    BalancedInsert(t, low, mid - 1, microseconds);
    BalancedInsert(t, mid + 1, high, microseconds);
}

void PrintTimes(
        int count,
        int elapsed,
        std::vector<int> &microseconds,
        std::string description) {
    int average = elapsed / count;
    int min = microseconds[0];
    int max = microseconds[0];
    for(auto sample : microseconds) {
        if (sample < min) {
            min = sample;
        }

        if (sample > max) {
            max = sample;
        }
    }


    std::cout << "+++++++++++++++++++++++++" << std::endl;
    std::cout << description << std::endl;
    std::cout << "average: " << average << std::endl;
    std::cout << "min: " << min << std::endl;
    std::cout << "max " << max << std::endl;
    std::cout << "-------------------------" << std::endl;

    microseconds.clear();
}

void TestLargeTree(int count, bool balanced) {
    std::cout << (balanced ? "balanced tree" : "unbalanced tree") << std::endl;
    BinSearchTree *t = new BinSearchTree();

    std::cout << "inserting: " << count << std::endl;

    std::vector<int> microseconds;

    auto start = std::chrono::steady_clock::now();
    if(balanced) {
        BalancedInsert(t, 1, count, microseconds);
    }
    else {
        for (int i = 0; i < count; ++i) {
            auto insertStart = std::chrono::steady_clock::now();
            t->insert(i);
            auto insertEnd = std::chrono::steady_clock::now();
            auto insertElapsed = std::chrono::duration_cast<std::chrono::microseconds>(insertEnd - insertStart);
            microseconds.push_back(insertElapsed.count());
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    PrintTimes(
            count,
            elapsed.count(),
            microseconds,
            "insert");

    start = std::chrono::steady_clock::now();
    for (int i = 0; i < count; ++i) {
        auto insertStart = std::chrono::steady_clock::now();
        t->find(i);
        auto insertEnd = std::chrono::steady_clock::now();
        auto insertElapsed = std::chrono::duration_cast<std::chrono::microseconds>(insertEnd - insertStart);
        microseconds.push_back(insertElapsed.count());
    }
    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    PrintTimes(
            count,
            elapsed.count(),
            microseconds,
            "find");

    start = std::chrono::steady_clock::now();
    for (int i = 0; i < count; ++i) {
        auto insertStart = std::chrono::steady_clock::now();
        t->iterFind(i);
        auto insertEnd = std::chrono::steady_clock::now();
        auto insertElapsed = std::chrono::duration_cast<std::chrono::microseconds>(insertEnd - insertStart);
        microseconds.push_back(insertElapsed.count());
    }
    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    PrintTimes(
            count,
            elapsed.count(),
            microseconds,
            "iterFind");

    start = std::chrono::steady_clock::now();
    std::cout << "size: " << t->size() << std::endl;
    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "size time: " << elapsed.count() << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << "depth: " << t->maxDepth() << std::endl;
    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "depth time: " << elapsed.count() << std::endl;

    std::cout << std::endl;
    delete t;
}


int main() {
    TestEmptyTree();

    //          8
    //     4         12
    //  2     6    10     14
   std::vector<int> smallBalanced {8, 4, 12, 2, 6, 10, 14};
   std::string smallBalancedExpected = MakeExpectation(2,14);
   TestSmallTree(smallBalanced, 1, 15, smallBalancedExpected, 3);

    //          6
    //     4         8
    //  2                10
    std::vector<int> smallOuter {6, 4, 8, 2, 10};

    //          6
    //     2         10
    //        4    8
    std::vector<int> smallInner {6, 2, 10, 4, 8 };
    std::string smallerBalanceExpected = MakeExpectation(2,10);
    TestSmallTree(smallOuter, 1, 11, smallerBalanceExpected, 3);
    TestSmallTree(smallInner, 1, 11, smallerBalanceExpected, 3);

    TestLargeTree(65535, true);
    TestLargeTree(65535, false);

    return 0;
}
