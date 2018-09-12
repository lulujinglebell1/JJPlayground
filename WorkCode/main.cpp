#include <vector>
#include <string>

using namespace std;
////////////////////////////////////////
bool isAN (char inChar){
    if ((inChar > 'a' && inChar < 'z') || (inChar > 'A' && inChar < 'Z') || (inChar > '0' && inChar < '9')){
        return true;
    }else{
        return false;
    }
}

bool isUp (char inChar){
    if (inChar > 'A' && inChar < 'Z'){
        return true;
    }else{
        return false;
    }
}
bool isLow (char inChar){
    if (inChar > 'a' && inChar < 'z'){
        return true;
    }else{
        return false;
    }
}

bool isP (string str){
    int right = str.length()-1;
    int left = 0;
    
    while (right > left){
        while (isAN (str[left]) != true) left++;
        while (isAN (str[right]) != true) right--;
        
        if(isUp(str[left]) == true && isLow(str[right]) == true){
            if (str[left] + 32 != str[right])
                return false;
        }
        if(isLow(str[left]) == true && isUp(str[right]) == true){
            if (str[right] + 32 != str[left])
                return false;
        }
        
        if (str[right] != str[left])
            return false;
        
        right--;
        left++;
    }
    
    return true;
}
/////////////////////////////// done
int sN (vector <int>& nums){
    int result;
    for (int i = 0; i < nums.size(); i++){
        result ^= nums[i];
    }
    return result;
}
//////////////////////////done
vector<int> tS (vector<int>& numbers, int target){
    int left = 0;
    int right = numbers.size() - 1;
    int sum = 0;
    vector<int> result;
    
    while (right > left){
        sum = numbers[left] + numbers[right];
        if (sum == target){
            result.push_back(left);
            result.push_back(right);
            return result;
        }
        if (sum > target){
            right--;
        }else{
            left++;
        }
    }
    return result;
}

//////////////////////////
class TS{
    
public:
    TS(){}
    void add(int number){}
    
    bool find (int value)
    {
        
        return false;
    }
};
//////////////////
//D2 X (26^2) + D1 X (26^1) + D0

int tToN(string s){
    int lenS = s.length();
    char curChar = s[0];
    int charD;
    int curResult;
    int totalResult = 0;
    
    for (int i = (lenS - 1); i <= 0; i++){
        curChar = s[i];
        charD = (int)curChar - 64;
        curResult = charD*26;
        totalResult = curResult
    }
    return result;
}
/////////////////////////////////
string convertToTitle(int n){
    int totalChar = n/26; //determin how many char needed to be return
    int lastChar = n%26; //determin what is the last char
    string returnS;
    char addChar = 'A';
    
    for(int i = 0; i <= totalChar; i++){
        if(i == totalChar){
            addChar = (char)((int)'A'+ lastChar);
            returnS += addChar;
            return returnS;
        }
        returnS += addChar;
        addChar++;
    }
    return returnS;
}
//////////////////////////////done
class MinStack{
private:
    class Node{
    public:
        int val;
        Node* next;
    };
public:
    Node* topNode;
    int minV;
    
    MinStack(){
        topNode = NULL;
        minV = 0;
    }
    
    void push(int x){
        if(topNode == NULL){
            Node* insertNode = new Node;
            insertNode->val = x;
            insertNode->next = NULL;
            minV = x;
            
        }else{
            Node* insertNode = new Node;
            insertNode->val = x;
            insertNode->next = topNode;
            topNode = insertNode;
            minV = min (x, minV);
        }
        
    }
    void pop(){
        if(topNode == NULL){
            printf("nothing to pop");
            return;
        }else{
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
    
    int top(){
        if(topNode == NULL){
            printf("nothing on the top");
            return 0;
        }else{
            return topNode->val;
        }
    }
    int getMin(){
        return 0;
    }
    
};
/////////////////////////////////done
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* gerIntersectionNode(ListNode* headA, ListNode* headB){
    int lenA = 0;
    int lenB = 0;
    int lenDiff = 0;
    ListNode* curA = headA;
    ListNode* curB = headB;
    
    while (curA != NULL){
        curA = curA->next;
        lenA++;
    }
    
    while (curB != NULL){
        curB = curB->next;
        lenB++;
    }
    
    if (lenA > lenB){
        lenDiff = lenA - lenB;
        while (lenA > lenB){
            curA = curA->next;
            lenA--;
        }
    }
    
    if(lenA < lenB){
        lenDiff = lenB - lenA;
        while (lenB > lenA){
            curB = curB->next;
            lenB--;
        }
    }
    while (curA != curB && curA != NULL){
        curA = curA->next;
        curB = curB->next;
    }
    if (curA == NULL){
        return NULL;
    }
    return curA;
}
////////////////////////

int mElement (vector<int>& nums){
    int curCount = 0;
    int vSize = nums.size();
    int outStanding = nums[0];
    
    for (int i = 0; i < (vSize - 1); i++){
        if (nums[i] == outStanding){
            curCount++;
        }else{
            if(curCount == 0){
                outStanding = nums[i];
            }
            curCount--;
        }
        return outStanding;
    }
    
}
///////////////////////////////



int main (void){
    
    return 0;
}
/////////////////////////

