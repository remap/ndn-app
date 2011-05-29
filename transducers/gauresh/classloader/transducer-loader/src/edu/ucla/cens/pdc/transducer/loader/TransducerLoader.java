package edu.ucla.cens.pdc.transducer.loader;

import java.io.*;
import java.net.*;
import java.security.CodeSource;
import java.security.SecureClassLoader;
import java.security.cert.Certificate;
import java.security.Permission;
import java.security.Policy;
import java.security.PermissionCollection;

public class TransducerLoader extends SecureClassLoader {

        protected URL urlBase;
        public boolean printLoadMessages = true;
	protected CodeSource cs;

        public TransducerLoader(String classBase) {
                super();
                try {
                        if (!(classBase.endsWith("/")))
                                classBase = classBase + "/";
                        urlBase = new URL(classBase);
                } catch (Exception e) {
                        throw new IllegalArgumentException(classBase);
                }

		Certificate arr[] = new Certificate[1];
		//Create the codesource object
		cs = new CodeSource(urlBase, arr);
        }

        byte[] getClassBytes(InputStream is) {
                ByteArrayOutputStream baos = new ByteArrayOutputStream();
                BufferedInputStream bis = new BufferedInputStream(is);
                boolean eof = false;
                while (!eof) {
                        try {
                                int i = bis.read();
                                if (i == -1)
                                        eof = true;
                                else baos.write(i);
                        } catch (IOException e) {
                                return null;
                        }
                }
                return baos.toByteArray();
        }

        protected Class findClass(String name) {
                String urlName = name.replace('.', '/');
                byte buf[];
                Class cl;
                try {
                        URL url = new URL(urlBase, urlName + ".class");
                        if (printLoadMessages)
                                System.out.println("Loading " + url);
                        InputStream is = url.openConnection().getInputStream();
                        buf = getClassBytes(is);
			Policy classPolicy = Policy.getPolicy();
			PermissionCollection pc = classPolicy.getPermissions(cs);
			pc.add(new java.lang.RuntimePermission("accessClassinPackage.{java.lang}"));
			System.out.println("i was here");
                        cl = defineClass(name, buf, 0, buf.length, cs);
                        return cl;
                } catch (Exception e) {
                        System.out.println("Can't load " + name + ": " + e);
                        return null;
                }
        }
}
                           
