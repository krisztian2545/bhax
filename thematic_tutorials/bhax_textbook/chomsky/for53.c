
int main(){

	int i, n = 5;
	int a = 0;
	int *d = &a;
	int *s = &a;

	for(i=0; i<n && (*d++ = *s++); ++i){}

	return 0;
}