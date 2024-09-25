import java.io.*;
import java.net.*;
import javax.crypto.SecretKey;
import java.util.Scanner;

public class Client{
	public static void main(String[] args){
		try{
		Scanner sc = new Scanner(System.in);
			Socket socket = new Socket("localhost",8080);
			SecretKey key = AESEncryptionUtil.getAESKey();
			String message = sc.nextLine();
			String encryptedMessage = AESEncryptionUtil.encrypt(message,key);
			System.out.println("Encrypted Message"+encryptedMessage);
			PrintWriter out = new PrintWriter(socket.getOutputStream(),true);
			out.println(encryptedMessage);
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			System.out.println("server response: " + in.readLine());
			in.close();
			out.close();
			socket.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
}
