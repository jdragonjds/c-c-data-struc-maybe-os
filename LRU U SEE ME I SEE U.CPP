class LRUCache
{
    private:

    public:
    public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};
 unordered_map<int, list<pair<int, int>>::iterator> um;
list<pair<int, int>> l;
int n = 0;

LRUCache::LRUCache(int N)
{
    um.clear();
    l.clear();
    n = N;
}

void LRUCache::set(int x, int y) 
{
    if (um.find(x) != um.end())
    {
        list<pair<int,int>>::iterator temp = um[x];
        l.erase(temp);
    }
    else if (l.size() == n)
    {
         pair<int, int> last = l.back();
         um.erase(last.first);
         l.pop_back();
    }
    l.push_front(make_pair(x,y));
    um[x] = l.begin();
}
 
int LRUCache::get(int x)
{
     if(um.find(x) != um.end())
     {
        list<pair<int,int>>::iterator temp = um[x];
        pair<int, int> x = *temp;
        l.erase(temp);
        l.push_front(x);
        um[x.first] = l.begin();
        return x.second;
     }
     return -1;
}
