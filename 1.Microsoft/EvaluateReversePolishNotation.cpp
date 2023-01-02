class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> resultStack;
        for(string iterator: tokens) {
            if(iterator == "*" || iterator == "/" || iterator == "+" || iterator == "-") {
                int tempResult = resultStack.top();
                resultStack.pop();

                if(iterator == "*")
                    tempResult = resultStack.top() * tempResult;
                else if(iterator == "/")
                    tempResult = resultStack.top() / tempResult;
                else if(iterator == "+")
                    tempResult = resultStack.top() + tempResult;
                else
                    tempResult = resultStack.top() - tempResult;
                
                resultStack.pop();
                resultStack.push(tempResult);
            } else {
                resultStack.push(stoi(iterator));
            }
        }
        return resultStack.top();
    }
};
