package rpgArquivo;
import java.util.Random;
public class Caverna {
	private Camara camara;
	private Aventureiro aventureiro;
	private JoaoDorminhoco Dorminhoco;
	public Caverna(int dimensao,Aventureiro aventureiro,JoaoDorminhoco Dorminhoco){
		Camara teste = new Camara(dimensao);
		this.setCamara(teste);
		this.setAventureiro(aventureiro);
		this.setDorminhoco(Dorminhoco);
	}
	public JoaoDorminhoco getDorminhoco() {
		return Dorminhoco;
	}

	public void setDorminhoco(JoaoDorminhoco dorminhoco) {
		Dorminhoco = dorminhoco;
	}
	public Camara getCamara() {
		return camara;
	}
	public void setCamara(Camara camara) {
		this.camara = camara;
	}
	public Aventureiro getAventureiro() {
		return aventureiro;
	}
	public void setAventureiro(Aventureiro aventureiro) {
		this.aventureiro = aventureiro;
	}
	public void iniciarCamara(int dimensao){
		Random num = new Random();
		int k= num.nextInt(3);
		if(k==0){
			this.getCamara().Iniciar(TipoCamara.camaraFacil,this.getAventureiro(),this.getDorminhoco());
			this.getCamara().setTipo(TipoCamara.camaraFacil);
		}else if(k==1){
			this.getCamara().Iniciar(TipoCamara.camaraDificil, this.getAventureiro(),this.getDorminhoco());
			this.getCamara().setTipo(TipoCamara.camaraDificil);
		}else{
			this.getCamara().Iniciar(TipoCamara.camaraErrada, this.getAventureiro(),this.getDorminhoco());
			this.getCamara().setTipo(TipoCamara.camaraErrada);
		}
	}
}