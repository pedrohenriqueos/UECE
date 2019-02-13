package rpgArquivo;

import java.util.Random;
import java.io.*;
public class Principal {
	public static void jogar(Caverna c) throws AcaoInvalidaException{
		int quant=0,controlprinc=0;
		boolean fim=false;
		while(!fim){
			if(controlprinc!=0){
				c.getAventureiro().getMemoria().delete();
				File a = new File(c.getAventureiro().getNameArquivo());
				c.getAventureiro().setMemoria(a);
				c.getAventureiro().setControl(0);
			}
			c.iniciarCamara(7);
		if(c.getCamara().getTipo()==TipoCamara.camaraErrada){
			while(true){
			Random num1 = new Random();
			int k = num1.nextInt(4);
			c.getCamara().getAventureiro().mover(k, c.getCamara());
			if(quant==2){
				c.getCamara().getJoao().setEstado(Estado.dormindo);
				quant=0;
			}
			if(c.getCamara().getJoao().getEstado()==Estado.acordado){
				c.getCamara().getJoao().mover(c.getCamara().getJoao().getMove(), c.getCamara());
				quant++;
			}
			if(c.getAventureiro().encontrouMensagem(c.getCamara())){
				System.out.println("O tesouro não está aqui haha");
				break;
			}
			}
		}else{
			while(true){
			Random num2 = new Random();
			int k = num2.nextInt(4);
			c.getCamara().getAventureiro().mover(k, c.getCamara());
			if(quant==2){
				c.getCamara().getJoao().setEstado(Estado.dormindo);
				quant=0;
			}
			if(c.getCamara().getJoao().getEstado()==Estado.acordado){
				c.getCamara().getJoao().mover(c.getCamara().getJoao().getMove(), c.getCamara());
				quant++;
			}
			if(c.getCamara().getJoao().getAcho()){
				System.out.println("JoaoDorminhoco matou o aventureiro");
				fim=true;
				break;
			}
			if(c.getAventureiro().encontrouTesouro(c.getCamara())){
				System.out.println("Tesouro encontrado, Parabens");
				fim=true;
				break;
			}
			}
		}
		controlprinc=1;
		}
		c.getAventureiro().EscreverMemoria();
	}
	public static void main(String[] args) throws AcaoInvalidaException {
		
		Aventureiro av = new Aventureiro("memoria.txt");
		JoaoDorminhoco j = new JoaoDorminhoco(Estado.dormindo);
		Caverna c = new Caverna(7,av,j);
		jogar(c);
	}

}