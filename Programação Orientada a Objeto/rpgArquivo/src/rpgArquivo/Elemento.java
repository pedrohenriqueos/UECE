package rpgArquivo;

public abstract class Elemento {
	private TipoElemento tipo;
	public Elemento(TipoElemento tipo){
		this.setTipo(tipo);
	}
	public TipoElemento getTipo() {
		return tipo;
	}
	public void setTipo(TipoElemento tipo) {
		this.tipo = tipo;
	}
	
}