#include <cstdio>
#include <cstdlib>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode* next) : val(0), next(next) {}
};

class Solution
{
    public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int sum = 0;
        int carry = 0;
        ListNode* sumList = new ListNode();
        ListNode* temp = sumList;
        while((l1 != nullptr) || (l2 != nullptr) || (carry == 1))
        {
            if ((l1 != nullptr) && (l2 != nullptr))
            {
                printf("l1:%d + l2:%d + carry:%d = ", (l1->val), (l2->val), carry);
                sum = (l1->val) + (l2->val) + carry;
                carry = sum/10;
                sum = sum - carry*10;
                printf("sum:%d + carry:%d\n", sum, carry);
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            else if ((l1 != nullptr) && (l2 == nullptr))
            {
                printf("l1:%d + l2:0 + carry:%d = ", (l1->val), carry);
                sum = (l1->val) + carry;
                carry = sum/10;
                sum -= carry*10;
                printf("sum:%d + carry:%d\n", sum, carry);
                l1 = l1 -> next;
            }
            else if ((l1 == nullptr) && (l2 != nullptr))
            {
                printf("l1:0 + l2:%d + carry:%d = ", (l2->val), carry);
                sum = (l2->val) + carry;
                carry = sum/10;
                sum -= carry*10;
                printf("sum:%d + carry:%d\n", sum, carry);
                l2 = l2 -> next;
            }
            else
            {
                temp->next = new ListNode(carry);
                carry = 0;
                continue;
            }

            temp->next = new ListNode(sum);
            temp = temp->next;
        }

        temp = sumList;
        sumList = sumList->next;
        delete(temp);

        return sumList;
    }

    static void printList(ListNode* node)
    {
        while(node != nullptr)
        {
            printf("%d -> ", node->val);
            node = node->next;
        }
        printf("nullptr\n");
    }
};

int main(int argc, char const *argv[])
{

    ListNode* l1 = new ListNode(1);
    ListNode* nodeptr = l1;
    for(int i = 0; i < 29; i++)
    {
        nodeptr->next = new ListNode(0);
        nodeptr = nodeptr->next;
    }
    nodeptr->next = new ListNode(1);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    ListNode* sumList = Solution::addTwoNumbers(l1, l2);

    Solution::printList(sumList);

    return 0;
}

