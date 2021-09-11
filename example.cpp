const int N = 200000;
struct segtree {
    long long sum[N<<1], tag[N], n;
    void upd(int p, long long d, int h) {
        sum[p] += d<<h;
        if(p < n) tag[p] += d;
    }
    void pull(int p) {
        for(int h=1; p>1; p>>=1, h++) sum[p>>1] = sum[p^1]+sum[p] + (tag[p>>1]<<h);
    }
    void push(int p) {
        for(int h = __lg(n); h >= 0; h--) {
            int i = p>>h;
            if(!tag[i>>1]) continue;
            upd(i,tag[i>>1],h);
            upd(i^1,tag[i>>1],h);
            tag[i>>1] = 0;
        }
    }
    void add(int l,int r,long long k) {
        int tl = l, tr = r, h = 0;
        push(l+n), push(r-1+n);
        for(l+=n, r+=n; l<r; l>>=1, r>>=1, h++) {
            if(l&1) upd(l++,k,h);
            if(r&1) upd(--r,k,h);
        }
        pull(tl+n), pull(tr-1+n);
    }
    long long query(int l,int r) { // [l,r)
        long long res = 0;
        push(l+n), push(r-1+n);
        for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if(l&1) res += sum[l++];
            if(r&1) res += sum[--r];
        }
        return res;
    }
    void init(long long v[],int _n) {
        n = _n;
        for(int i = 0; i < n; i++) sum[i+n] = v[i];
        for(int i = n-1; i > 0; i--) sum[i] = sum[i<<1]+sum[i<<1|1];
    }
} sgt;
