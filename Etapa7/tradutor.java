import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.io.PrintWriter;

public class tradutor {
	public static void main(String[] args) {
		try {
			FileReader arq = new FileReader("saida.tac");
			PrintWriter pw = new PrintWriter("output.s");
			BufferedReader lerArq = new BufferedReader(arq);
			String linha = lerArq.readLine(); 

			
			pw.printf(".section .data\n");
			pw.printf("\t zero: .quad 0\n");
			pw.printf(".section . text\n");
			pw.printf("\t .extern printf\n");
			pw.printf("\t .global _start\n");
			pw.printf("_start:\n");

			while (linha != null) {
				String base = linha.substring(0,3);
				System.out.printf("base   %s\n", base);
				String posResult = linha.substring(5,8);
				System.out.printf("Pos Result   %s\n", posResult);

				if(posResult.contains("PRI")){
					String posPrint = linha.substring(14,17);
					String nomePrint = linha.substring(18,20);
					System.out.printf("Print : Pos.MemoriaResultado   %s\n", posPrint);
					System.out.printf("NOme: Pos.MemoriaResultado   %s\n", nomePrint);
					traduzprintf(posPrint, nomePrint, pw);
					
				}
				else if(posResult.contains("FPR")){
					String posPrint = linha.substring(14,17);
					String nomePrint = linha.substring(19,21);
					System.out.printf("Print : Pos.MemoriaResultado   %s\n", posPrint);
					System.out.printf("NOme: Pos.MemoriaResultado   %s\n", nomePrint);
					traduzprintf(posPrint, nomePrint, pw);
					
				}
				else{
					String nomeResult = linha.substring(9,11);
					System.out.printf("NomeRseult %s\n", nomeResult);
					String igual = linha.substring(14,17);
					System.out.printf("igual %s\n", igual);
					String posArg1 = linha.substring(17,20);
					System.out.printf("pOS ARG1 %s\n",  posArg1);	
					String nomeArg1 = linha.substring(21,23);
					System.out.printf("NomeArg1 %s\n",  nomeArg1);
					String op = linha.substring(25,28);
	
					if(op.contains("ADD") || op.contains("SUB") || op.contains("DIV"))	
					{
						String aux = linha.substring(29);
						if(aux.contains("SP") || aux.contains("Rx")){
							String nomeArg2 = linha.substring(33,35);
							String posArg2 = linha.substring(29,32);
							System.out.printf("PosArg2   %s\n", posArg2);
							System.out.printf("NOmeArg2   %s\n", nomeArg2);
							traduz(posResult, nomeResult, posArg1, nomeArg1, op, nomeArg2, posArg2, pw);
						}
						else{
							String valor = linha.substring(29);
							System.out.printf("valor  %s\n", valor);
							traduzvalor(posResult, nomeResult, posArg1, nomeArg1, op, valor, pw);
						}
					}

					else if(op.contains("FAD") || op.contains("FSU") || op.contains("FDI"))	
					{	String op2 = linha.substring(26,29);
						String aux = linha.substring(30);
						if(aux.contains("(SP)") || aux.contains("(Rx)")){
							String nomeArg2 = linha.substring(34,36);
							String posArg2 = linha.substring(30,33);
							System.out.printf("PosArg2   %s\n", posArg2);
							System.out.printf("NOmeArg2   %s\n", nomeArg2);
							traduz(posResult, nomeResult, posArg1, nomeArg1, op2, nomeArg2, posArg2, pw);
						}
						else{
							String valor = linha.substring(30);
							System.out.printf("valor  %s\n", valor);
							traduzvalor(posResult, nomeResult, posArg1, nomeArg1, op2, valor, pw);
						}
					}
					else if(op.contains("MUL"))	
					{	String op2 = linha.substring(25,29);
						String aux = linha.substring(30);
						if(aux.contains("SP") || aux.contains("Rx")){
							String nomeArg2 = linha.substring(34,36);
							String posArg2 = linha.substring(30,33);
							System.out.printf("PosArg2   %s\n", posArg2);
							System.out.printf("NOmeArg2   %s\n", nomeArg2);
							traduz(posResult, nomeResult, posArg1, nomeArg1, op2, nomeArg2, posArg2, pw);
						}
						else{
							String valor = linha.substring(30);
							System.out.printf("valor  %s\n", valor);
							traduzvalor(posResult, nomeResult, posArg1, nomeArg1, op2, valor, pw);
						}
					}
					else if(op.contains("FMU"))	
					{	String op2 = linha.substring(26,30);
						String aux = linha.substring(31);
						if(aux.contains("(SP)") || aux.contains("(Rx)")){
							String nomeArg2 = linha.substring(35,37);
							String posArg2 = linha.substring(31,34);
							System.out.printf("PosArg2   %s\n", posArg2);
							System.out.printf("NOmeArg2   %s\n", nomeArg2);
							traduz(posResult, nomeResult, posArg1, nomeArg1, op2, nomeArg2, posArg2, pw);
						}
						else{
							String valor = linha.substring(31);
							System.out.printf("valor  %s\n", valor);
							traduzvalor(posResult, nomeResult, posArg1, nomeArg1, op2, valor, pw);
						}
					}
					else if(op.contains("MOV"))	
					{
						String aux = linha.substring(30);
						if(aux.contains("SP") || aux.contains("Rx")){
							String nomeArg2 = linha.substring(34,36);
							String posArg2 = linha.substring(30,33);
							System.out.printf("PosArg2   %s\n", posArg2);
							System.out.printf("NOmeArg2   %s\n", nomeArg2);
							traduzmove(posResult, nomeResult, posArg1, nomeArg1, nomeArg2, posArg2, pw);
						}
						else{
							String valor = linha.substring(30);
							System.out.printf("valor  %s\n", valor);
							traduzmoveValor(posResult, nomeResult, posArg1, nomeArg1, valor, pw);
						}
					}
					else
					{	
						String aux = linha.substring(31);
						if(aux.contains("(SP)") || aux.contains("(Rx)")){
							String nomeArg2 = linha.substring(35,37);
							String posArg2 = linha.substring(31,34);
							System.out.printf("PosArg2   %s\n", posArg2);
							System.out.printf("NOmeArg2   %s\n", nomeArg2);
							traduzmove(posResult, nomeResult, posArg1, nomeArg1, nomeArg2, posArg2, pw);
						}
						else{
							String valor = linha.substring(31);
							System.out.printf("valor  %s\n", valor);
							traduzmoveValor(posResult, nomeResult, posArg1, nomeArg1, valor, pw);
						}
					}
					
				}
				linha = lerArq.readLine(); 
			}
			pw.flush();
			pw.close();
			arq.close();
		} catch (IOException e) {
			System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
		}

		System.out.println();
	}

	public static void traduzmove(String posResult, String nomeResult, String posArg1, String nomeArg1, String nomeArg2, String posArg2, PrintWriter pw){
		pw.printf("\t MOVL %s(R%s), %s(R%s) \n",posArg2, nomeArg2, posResult, nomeResult);
	}
	public static void traduzmoveValor(String posResult, String nomeResult, String posArg1, String nomeArg1, String valor, PrintWriter pw){
		pw.printf("\t MOVL %s, %s(R%s) \n",valor,posResult, nomeResult);
	}

	public static void traduz(String posResult, String nomeResult, String posArg1, String nomeArg1, String op, String nomeArg2, String posArg2, PrintWriter pw){
		pw.printf("\t MOVL %s(R%s), %%RAX \n",posArg1, nomeArg1);
		pw.printf("\t %sL %s(R%s), %%RAX \n", op, posArg2, nomeArg2);
		pw.printf("\t MOVL %%RAX, %s(R%s) \n",posResult, nomeResult);
	}
	public static void traduzvalor(String posResult, String nomeResult, String posArg1, String nomeArg1, String op, String valor, PrintWriter pw){
		pw.printf("\t MOVL %s(R%s), %%RAX \n", posArg1, nomeArg1);
		pw.printf("\t %sL %s, %%RAX \n", op, valor, posArg1, nomeArg1);
		pw.printf("\t MOVL %%RAX, %s(R%s) \n",posResult, nomeResult);
	}
	public static void traduzprintf(String posResult, String nomeResult, PrintWriter pw){
		pw.printf("\t PUSHL %s(R%s) \n",posResult, nomeResult);
		pw.printf("\t PUSHL $intf\n");
		pw.printf("\t CALL printf \n");
	}
}

