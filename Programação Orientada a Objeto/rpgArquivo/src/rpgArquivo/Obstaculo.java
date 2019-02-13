package rpgArquivo;

public class Obstaculo extends Elemento{
	private EResistencia resistencia;
	private int x,y;
	public Obstaculo(EResistencia resistencia){
		super(TipoElemento.Obstaculo);
		this.setResistencia(resistencia);
	}
	public EResistencia getResistencia() {
		return resistencia;
	}
	public void setResistencia(EResistencia resistencia) {
		this.resistencia = resistencia;
	}
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}
}