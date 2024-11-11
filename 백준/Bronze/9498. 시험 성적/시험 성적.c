int main(void)
{
    int a;
    scanf("%d", &a);
    if ((a>=90)&&(a<=100)){
        printf("A\n");
    }
    else if (a>=80){
        printf("B\n");
    }
    else if (a>=70){
        printf("C\n");
    }
    else if (a>=60){
        printf("D\n");
    }
    else if ((a<=59)){
        printf("F\n");
    }
    return 0;
}