package com.mycompany.gameproject;
import java.awt.Canvas;
import java.awt.Dimension;
import javax.swing.JFrame;
public class Window extends Canvas{
	private static final long serialVersionUID = -8670171153876043137L;
	public Window(int width,int height,String tittle,Game game) {
		JFrame jframe=new JFrame(tittle);
		jframe.setPreferredSize(new Dimension(width,height));
		jframe.setMaximumSize(new Dimension(width,height));
		jframe.setMinimumSize(new Dimension(width,height));
		jframe.setResizable(false);
		jframe.setLocationRelativeTo(null);
		jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jframe.add(game);
		jframe.setVisible(true);
		game.start();
   }
}
