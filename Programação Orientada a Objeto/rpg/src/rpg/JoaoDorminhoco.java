package rpg;

public class JoaoDorminhoco extends Personagem{
	private Estado estado;
	private boolean acho;
	private int move;
	public JoaoDorminhoco(Estado estado) {
		super(TipoElemento.JoaoDorminhoco);
		this.setEstado(estado);
	}
	public int getMove() {
		return move;
	}

	public void setMove(int move) {
		this.move = move;
	}

	public boolean getAcho() {
		return acho;
	}
	public void setAcho(boolean acho) {
		this.acho = acho;
	}
	public Estado getEstado() {
		return estado;
	}
	public void setEstado(Estado estado) {
		this.estado = estado;
	}
}