#include <cassert>
#include <iostream>
#include <vector>

namespace search {
namespace sublist_search {
struct Node {
    uint32_t data = 0;
    Node *next{};
};

void printLinkedList(Node *start) {
    while (start != nullptr) {
        std::cout << "->" << start->data;
        start = start->next;
    }
    std::cout << std::endl;
}

Node *makeLinkedList(const std::vector<uint64_t> &data) {
    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i : data) {
        Node *node = new Node;
        node->data = i;
        node->next = nullptr;
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }
    return head;
}

bool sublistSearch(Node *sublist, Node *mainList) {
    if (sublist == nullptr || mainList == nullptr) {
        return false;
    }

    Node *target_ptr = sublist;

    while (mainList != nullptr) {
        Node *main_ptr = mainList;

        while (target_ptr != nullptr) {
            if (main_ptr == nullptr) {
                return false;

            } else if (main_ptr->data == target_ptr->data) {
                target_ptr = target_ptr->next;
                main_ptr = main_ptr->next;

            } else {
                break;
            }
        }

        if (target_ptr == nullptr) {
            return true;
        }

        target_ptr = sublist;

        mainList = mainList->next;
    }

    return false;
}

}
}

class TestCases {
 private:
    template <typename T>
    void log(T msg) {
        std::cout << "[TESTS] : ---> " << msg << std::endl;
    }

 public:
    void runTests() {
        log("Running Tests...");

        testCase_1();
        testCase_2();
        testCase_3();

        log("Test Cases over!");
        std::cout << std::endl;
    }

    void testCase_1() {
        const bool expectedOutput = true;
        log("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            "~");
        log("This is test case 1 for sublist search Algorithm : ");
        log("Description:");
        log("   EDGE CASE : Only contains one element");

        std::vector<uint64_t> sublistData = {
            6};
        std::vector<uint64_t> mainlistData = {
            2, 5, 6, 7,
            8};

        search::sublist_search::Node *sublistLL =
            search::sublist_search::makeLinkedList(
                sublistData);
        search::sublist_search::Node *mainlistLL =
            search::sublist_search::makeLinkedList(
                mainlistData);

        bool exists = search::sublist_search::sublistSearch(
            sublistLL, mainlistLL);

        log("Checking assert expression...");
        assert(exists == expectedOutput);
        log("Assertion check passed!");

        log("[PASS] : TEST CASE 1 PASS!");
        log("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            "~");

        delete (sublistLL);
        delete (mainlistLL);
    }

    void testCase_2() {
        const bool expectedOutput = true;

        log("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            "~");
        log("This is test case 2 for sublist search Algorithm : ");
        log("Description:");
        log("   contains main list of 100 elements and sublist of 20");

        std::vector<uint64_t> sublistData(
            20);
        std::vector<uint64_t> mainlistData(
            100);

        for (int i = 0; i < 100; i++) {
            mainlistData[i] = i + 1;
        }

        int temp = 0;
        for (int i = 45; i < 65; i++) {
            sublistData[temp] = i + 1;
            temp++;
        }

        search::sublist_search::Node *sublistLL =
            search::sublist_search::makeLinkedList(
                sublistData);
        search::sublist_search::Node *mainlistLL =
            search::sublist_search::makeLinkedList(
                mainlistData);

        bool exists = search::sublist_search::sublistSearch(
            sublistLL, mainlistLL);

        log("Checking assert expression...");
        assert(exists == expectedOutput);
        log("Assertion check passed!");

        log("[PASS] : TEST CASE 2 PASS!");
        log("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            "~");
    }

    void testCase_3() {
        const bool expectedOutput = false;

        log("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            "~");
        log("This is test case 3 for sublist search Algorithm : ");
        log("Description:");
        log("   contains main list of 50 elements and sublist of 20");

        std::vector<uint64_t> sublistData(20);
        std::vector<uint64_t> mainlistData(
            50);

        for (int i = 0; i < 50; i++) {
            mainlistData.push_back(i + 1);
        }

        for (int i = 45; i < 65; i++) {
            sublistData.push_back(i + 1);
        }

        search::sublist_search::Node *sublistLL =
            search::sublist_search::makeLinkedList(
                sublistData);
        search::sublist_search::Node *mainlistLL =
            search::sublist_search::makeLinkedList(
                mainlistData);

        bool exists = search::sublist_search::sublistSearch(
            sublistLL, mainlistLL);

        log("Checking assert expression...");
        assert(exists == expectedOutput);
        log("Assertion check passed!");

        log("[PASS] : TEST CASE 3 PASS!");
        log("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            "~");
    }
};

static void test() {
    TestCases tc;
    tc.runTests();
}

int main(int argc, char *argv[]) {
    test();
    std::vector<uint64_t> mainlistData = {
        2, 5, 6, 7, 8};
    std::vector<uint64_t> sublistData = {6, 8};

    search::sublist_search::Node *mainlistLL =
        search::sublist_search::makeLinkedList(mainlistData);
    search::sublist_search::Node *sublistLL =
        search::sublist_search::makeLinkedList(
            sublistData);

    bool exists = search::sublist_search::sublistSearch(
        sublistLL,
        mainlistLL);

    std::cout << "Sublist: " << std::endl;
    search::sublist_search::printLinkedList(sublistLL);

    std::cout << "Main list: " << std::endl;
    search::sublist_search::printLinkedList(mainlistLL);
    std::cout << std::endl;

    if (exists) {
        std::cout << "[TRUE] - sublist found in main list\n";
    } else {
        std::cout << "[FALSE] - sublist NOT found in main list\n";
    }
    return 0;
}
