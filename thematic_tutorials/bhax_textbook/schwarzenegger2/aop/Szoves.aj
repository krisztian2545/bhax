
public aspect Szoves {
	
	pointcut fun(): call( public void kiir(java.io.PrintWriter));
	
	before(): fun() {
		System.out.println("Kiiratas elott ... ");
	}
	
	pointcut fun2(): call( public void LZWBinFa.egyBitFeldolg(char) );
	
	before(): fun2() {
		Object[] args = thisJoinPoint.getArgs();
		System.out.println("binfa input: " + args[0].toString());
	}
	
}
