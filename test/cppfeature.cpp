class A
{
public:
    const static int a;
};
const int A::a = 0;
int main()
{
    int b = A::a;
    return 0;
}
