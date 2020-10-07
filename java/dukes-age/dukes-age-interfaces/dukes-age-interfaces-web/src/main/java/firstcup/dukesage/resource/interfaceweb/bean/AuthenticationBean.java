/*
 * JEE 7 Archetype, base project for a 3 tiers JEE7 maven application
 *
 * Copyright (c) 2016, Luís Ribeiro or third-party contributors as
 * indicated by the @author tags or express copyright attribution
 * statements applied by the authors.  All third-party contributions are
 * distributed under license by Luís Ribeiro.
 *
 * This copyrighted material is made available to anyone wishing to use, modify,
 * copy, or redistribute it subject to the terms and conditions of the GNU
 * Lesser General Public License, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this distribution; if not, please send an email to:
 * luismmribeiro@gmail.com
 */
package firstcup.dukesage.resource.interfaceweb.bean;

import java.io.IOException;
import java.io.Serializable;

import javax.enterprise.context.RequestScoped;
import javax.faces.context.FacesContext;
import javax.inject.Named;

import org.apache.shiro.SecurityUtils;

/**
 * Bean that handles login actions (for now, just logout action)
 * 
 * @author <a href="mailto:luismmribeiro@gmail.com">Luis Ribeiro</a>
 */
@Named
@RequestScoped
public class AuthenticationBean implements Serializable {
    private static final long serialVersionUID = 1L;
    
    private static final String LOGIN_PAGE = "login.xhtml";
    private static final String LOGIN_URL = "/" + LOGIN_PAGE;

    public void logout() throws IOException {
        SecurityUtils.getSubject().logout();
        FacesContext.getCurrentInstance().getExternalContext().redirect(LOGIN_PAGE);
    }
    
    public boolean isLoginPage() {
        String pageName = FacesContext.getCurrentInstance().getViewRoot().getViewId();
        
        if(pageName == null) {
            return false;
        }
        
        return pageName.startsWith(LOGIN_URL);
    }
}
