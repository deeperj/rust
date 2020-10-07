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

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.EnumType;
import javax.persistence.Enumerated;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Lob;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.apache.shiro.SecurityUtils;
import firstcup.dukesage.resource.commons.model.AbstractEntity;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

/**
 * Audit entity. 
 *
 * @author <a href="mailto:luismmribeiro@gmail.com">Luis Ribeiro</a>
 */
@Entity
public class Audit implements Serializable {
    private static final long serialVersionUID = 1L;

    private static final Logger LOGGER = LogManager.getLogger(Audit.class);

    /** Manages the JSON generation */
    private static final ObjectMapper mapper = new ObjectMapper();

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private Long entityId;
    private String entityName;
    @Lob
    private String content;    
    @Enumerated(EnumType.STRING)
    private ActionType actionType;
    @Temporal(TemporalType.TIMESTAMP)
    private Date timestamp;
    private String userId;


    public Audit() {
        super();
        timestamp = new Date();
    }

    /**
     * Create an Audit entity 
     * 
     * @param entity
     * @param actionType
     */
    public Audit(AbstractEntity entity, ActionType actionType) {
        this();
        assert(entity != null);
        entityId = entity.getId();
        entityName = entity.getClass().getName();
        content = serializeEntity(entity);
        this.actionType = actionType;
        
        Object principal = SecurityUtils.getSubject().getPrincipal(); 
        userId = principal.toString();
    }

    private String serializeEntity(AbstractEntity entity) {
        String result = null;
        try {
            result = mapper.writerWithDefaultPrettyPrinter().writeValueAsString(entity);
        }
        catch (JsonProcessingException e) {
            LOGGER.error("Error serializing the entity: " + e.toString(), e);
        }
        return result;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getEntityName() {
        return this.entityName;
    }

    public void setEntityName(String entityName) {
        this.entityName = entityName;
    }

    public ActionType getActionType() {
        return actionType;
    }

    public void setActionType(ActionType actionType) {
        this.actionType = actionType;
    }

    public Date getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(Date timestamp) {
        this.timestamp = timestamp;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public Long getEntityId() {
        return entityId;
    }

    public void setEntityId(Long entityId) {
        this.entityId = entityId;
    }
}
