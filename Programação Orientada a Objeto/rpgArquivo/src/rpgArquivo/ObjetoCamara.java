package rpgArquivo;

public class ObjetoCamara extends Elemento{
	private String nome;
	public ObjetoCamara(String nome,TipoElemento tipo){
		super(tipo);
		this.setNome(nome);
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	
}