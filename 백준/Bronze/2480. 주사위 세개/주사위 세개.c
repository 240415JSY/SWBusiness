int main(void){
    int a, b, c, money;
    scanf("%d %d %d", &a, &b, &c);
    if ((a == b) || (b == c)){
        money = 1000 + b * 100;
    }
    if ((c == a)){
        money = 1000 + a * 100;
    }
    if ((a != b) && (b != c) && (c != a)){
        if ((a > b) && (a > c)){
            money = a * 100;
        }
        if ((b > c) && (b > a)){
            money = b * 100;
        }
        if ((c > a) && (c > b)){
            money = c * 100;
        }
    }
    if ((a == b) && (b == c)){
        money = 10000 + a * 1000;
    }
    printf("%d", money);
    return 0;
}