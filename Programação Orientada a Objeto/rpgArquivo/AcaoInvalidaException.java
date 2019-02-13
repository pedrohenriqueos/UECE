package rpgArquivo;

public class AcaoInvalidaException extends Exception{
	private String save;
	private static final long serialVersionUID = 1L;
	public AcaoInvalidaException(Movimento a){
		save=a+" é inválido,limite da matriz";
	}
	public AcaoInvalidaException(){
		save="obstaculo encontrado";
	}
	public String toString(){
		return save;
	}
}