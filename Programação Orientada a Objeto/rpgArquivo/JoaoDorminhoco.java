package rpgArquivo;

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

	public boolean verificaAventureiro(Camara c){
		return (this.getX()!=0 &&this.getY()!=0 && this.getX()!=c.getDimensao()-1 && this.getY()!=c.getDimensao()-1)?(
				c.getCenario()[this.getX()+1][this.getY()]==TipoElemento.Aventureiro ||
				c.getCenario()[this.getX()][this.getY()+1]==TipoElemento.Aventureiro ||
				c.getCenario()[this.getX()-1][this.getY()]==TipoElemento.Aventureiro ||
				c.getCenario()[this.getX()][this.getY()-1]==TipoElemento.Aventureiro):(this.getX()!=0 && this.getX()!=c.getDimensao()-1 && this.getY()!=c.getDimensao()-1)?(
						c.getCenario()[this.getX()+1][this.getY()]==TipoElemento.Aventureiro ||
						c.getCenario()[this.getX()][this.getY()+1]==TipoElemento.Aventureiro ||
						c.getCenario()[this.getX()-1][this.getY()]==TipoElemento.Aventureiro):(this.getY()!=0 && this.getX()!=c.getDimensao()-1 && this.getY()!=c.getDimensao()-1)?
								c.getCenario()[this.getX()+1][this.getY()]==TipoElemento.Aventureiro ||
								c.getCenario()[this.getX()][this.getY()+1]==TipoElemento.Aventureiro ||
								c.getCenario()[this.getX()][this.getY()-1]==TipoElemento.Aventureiro:(this.getX()!=0 && this.getY()!=0 && this.getX()!=c.getDimensao()-1)?
										c.getCenario()[this.getX()-1][this.getY()]==TipoElemento.Aventureiro ||
										c.getCenario()[this.getX()+1][this.getY()]==TipoElemento.Aventureiro ||
										c.getCenario()[this.getX()][this.getY()-1]==TipoElemento.Aventureiro:(this.getX()!=0 && this.getY()!=0 && this.getY()!=c.getDimensao()-1)?
												c.getCenario()[this.getX()-1][this.getY()]==TipoElemento.Aventureiro ||
												c.getCenario()[this.getX()][this.getY()+1]==TipoElemento.Aventureiro ||
												c.getCenario()[this.getX()][this.getY()-1]==TipoElemento.Aventureiro:(this.getX()!=c.getDimensao()-1 && this.getY()!=c.getDimensao()-1)?
														c.getCenario()[this.getX()+1][this.getY()]==TipoElemento.Aventureiro ||
														c.getCenario()[this.getX()][this.getY()+1]==TipoElemento.Aventureiro:(this.getX()!=0 && this.getY()!=0)?
																c.getCenario()[this.getX()-1][this.getY()]==TipoElemento.Aventureiro ||
																c.getCenario()[this.getX()][this.getY()-1]==TipoElemento.Aventureiro:(this.getX()!=0 && this.getY()!=c.getDimensao()-1)?
																		c.getCenario()[this.getX()-1][this.getY()]==TipoElemento.Aventureiro ||
																		c.getCenario()[this.getX()][this.getY()+1]==TipoElemento.Aventureiro:
																				c.getCenario()[this.getX()+1][this.getY()]==TipoElemento.Aventureiro ||
																				c.getCenario()[this.getX()][this.getY()-1]==TipoElemento.Aventureiro;
	}
}