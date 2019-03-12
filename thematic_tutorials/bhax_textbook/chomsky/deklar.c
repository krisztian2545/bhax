int main(){
	
	int a;

	int *b = &a;

	//int &r = a; ilyen nincs c-ben

	int c[5];

	//int (&tr)[5] = c; ilyen nincs c-ben

	int *d[5];

	int *h ();

	int *(*l) ();

	int (*v (int c)) (int a, int b);

	int (*(*z) (int)) (int, int);

	return 0;
}