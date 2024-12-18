void readdisplay2() {
    char c;
    int i;
    char str[80];
    short s;
    float f;

    printf("Enter a character, an integer, a string (max 80 characters), a short, and a float: ");
    scanf(" %c %d %s %hd %f", &c, &i, str, &s, &f);
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    printf("%c, %d, %s, %hd, %.4f\n", c, i, str, s, f);
    displaySize(c,i,str,s,f);
}
void displaySize(char c, int i, char *str, short s,float f) {

    printf("Size of 'char' type: %u bytes\n", sizeof(char));
    printf("Size of 'int' type: %u bytes\n", sizeof(int));
    printf("Size of 'char array' type (max 80 chars): %u bytes\n", sizeof(str));
    printf("Size of 'short' type: %u bytes\n", sizeof(short));
    printf("Size of 'float' type: %u bytes\n", sizeof(float));

    printf("\nSize of variable 'c' (char): %u bytes\n", sizeof(c));
    printf("Size of variable 'i' (int): %u bytes\n", sizeof(i));
    printf("Size of variable 'str' (char array): %u bytes\n", sizeof(str));
    printf("Size of variable 's' (short): %u bytes\n", sizeof(s));
    printf("Size of variable 'f' (float): %u bytes\n", sizeof(f));
}
int main() {
    readdisplay2();
    return 0;
}

