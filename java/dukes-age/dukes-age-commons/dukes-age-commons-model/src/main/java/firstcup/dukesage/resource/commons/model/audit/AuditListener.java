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
package firstcup.dukesage.resource.commons.model.audit;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.PostPersist;
import javax.persistence.PostRemove;
import javax.persistence.PostUpdate;

import firstcup.dukesage.resource.commons.model.AbstractEntity;

/**
 * Listener for auditing purposes. When an Entity is changed in the project (either a creation, modification or 
 * removal) an Audit Entity is created for tracking every modification on the application.
 * 
 * @author <a href="mailto:luismmribeiro@gmail.com">Luis Ribeiro</a>
 */
public class AuditListener {    
    @PersistenceContext
    private EntityManager em;

    @PostPersist
    public void prePersist(AbstractEntity entity) {
        persistAudit(entity, ActionType.CREATE);
    }

    @PostUpdate
    public void preUpdate(AbstractEntity entity) {
        persistAudit(entity, ActionType.UPDATE);
    }

    @PostRemove
    public void preDestroy(AbstractEntity entity) {
        persistAudit(entity, ActionType.DELETE);
    }

    private void persistAudit(AbstractEntity entity, ActionType actionType) {
        Audit a = new Audit(entity, actionType);

        em.persist(a);
    }
}
