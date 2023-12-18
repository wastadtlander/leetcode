class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        count = 0;
        for (int i = 0; i < products.size(); ++i) {
            menu[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double bill = 0;
        for (int i = 0; i < product.size(); ++i) {
            bill += amount[i] * menu[product[i]];
        }
        return count % n == 0 ? bill * ((100 - discount) / 100.0) : bill;
    }
private:
    unordered_map<int, int> menu;
    int n, discount, count;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
