package rpg;

public class AcaoInvalidaException extends Exception{
	private static final long serialVersionUID = 1L;
	private String save;
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
