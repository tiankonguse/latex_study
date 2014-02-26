int rands() {
        static int x=1364684679;
        x+=(x<<2)+1;
        return x;

}

