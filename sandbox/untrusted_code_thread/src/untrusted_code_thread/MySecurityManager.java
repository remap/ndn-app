/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package untrusted_code_thread;

import java.io.FilePermission;
import java.security.Permission;
import java.util.logging.Logger;

/**
 *
 * @author Derek Kulinski
 */
public class MySecurityManager extends SecurityManager {
	static final Logger l = Logger.getLogger(MySecurityManager.class.getName());

	private Object secret;

	public MySecurityManager(Object pass)
	{
		secret = pass;
	}

	void disable(Object pass)
	{
		if (pass == secret)
			secret = null;
	}

	@Override
	public void checkPermission(Permission perm)
	{
//		l.log(Level.INFO, "Checking permission: {0}", perm.toString());
		if (secret != null && perm instanceof FilePermission)
			throw new SecurityException("Accessing files is not permitted");

		return;
	}

	@Override
	public void checkDelete(String file)
	{
//		l.log(Level.INFO, "Checking deletion: {0}", file);

		if (secret != null)
			throw new SecurityException("Accessing files is not permitted");

		return;
	}

	@Override
	public void checkSecurityAccess(String target)
	{
		System.out.println("Security access: " + target);
		super.checkSecurityAccess(target);
	}
}
