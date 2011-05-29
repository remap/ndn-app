/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer.server;

/**
 *
 * @author Derek Kulinski
 */
public class StreamInfo {
	public StreamInfo(String name, int number)
	{
		this.name = name;
		this.number = number;
	}

	public final String name;

	public final int number;
}