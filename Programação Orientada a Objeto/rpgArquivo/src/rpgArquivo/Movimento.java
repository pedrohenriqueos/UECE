package rpgArquivo;

public enum Movimento {
	up(0),
	down(3),
	left(2),
	right(1);
	private int valor;
	Movimento(int valor){
		this.valor = valor;
	}
	public int getValor(){
		return this.valor;
	}
}