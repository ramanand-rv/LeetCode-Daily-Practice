class MyHashMap {
public:
    int um[1000001];
    MyHashMap() {
        memset(um,-1,sizeof(um));
    }
    
    void put(int key, int value) {
        um[key]=value;
    }
    
    int get(int key) {
        return um[key];
    }
    
    void remove(int key) {
        um[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */