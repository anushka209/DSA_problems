class StockSpanner {
public:
    stack<pair<int,int>>st;   //pair of price and span
    StockSpanner() {    
    }
    int next(int price) {
       int span=1;    //currently span is 1 for itself
       while(!st.empty() && st.top().first<=price)
       {
         span=span+st.top().second;
         st.pop();
       }
       st.push({price,span});
       return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */