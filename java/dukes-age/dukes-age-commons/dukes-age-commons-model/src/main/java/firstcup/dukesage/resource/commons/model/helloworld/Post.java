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
package firstcup.dukesage.resource.commons.model.helloworld;

import java.text.SimpleDateFormat;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Lob;
import javax.persistence.PrePersist;
import javax.persistence.PreUpdate;

import firstcup.dukesage.resource.commons.model.AbstractEntity;

/**
 * Example Entity. Represents a Post on a blog
 * 
 * @author <a href="mailto:luismmribeiro@gmail.com">Luis Ribeiro</a>
 */
@Entity
public class Post extends AbstractEntity {
	private static final long serialVersionUID = 1L;
	
	private static final int DEFAULT_MAX_TEXT_SIZE = 100;
	
	private String author;
	private String title;
	@Lob
	private String text;
	private Date postDateTime;
	
	
    @PrePersist
    @PreUpdate
	public void setCurrentDate() {
		postDateTime = new Date();
	}
	
	public String getAuthor() {
		return author;
	}
	public void setAuthor(String author) {
		this.author = author;
	}
	public String getText() {
		return text;
	}
	public void setText(String text) {
		this.text = text;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public Date getPostDateTime() {
		return postDateTime;
	}
	public void setPostDateTime(Date postDateTime) {
		this.postDateTime = postDateTime;
	}
	
	public String[] getDateParts() {
		if(postDateTime == null) {
			return new String[] {"", "", ""};
		}
		String temp = new SimpleDateFormat("dd-MMM-yyyy").format(postDateTime);
		return temp.split("-");
	}
	
	public String getLimitedSizeText() {
	    return getLimitedSizeText(DEFAULT_MAX_TEXT_SIZE);
	}
	
	public String getLimitedSizeText(int size) {
        if(text == null) {
            return "";
        }
        
        int textSize = size > text.length() ? text.length() : size;
        return text.substring(0, textSize);
	}
	
	protected StringBuilder appendPropertiesToToString(StringBuilder stringBuilder) {
		super.appendPropertiesToToString(stringBuilder);
		
		appendItemToToString(stringBuilder, "author", this.getAuthor());
		appendItemToToString(stringBuilder, "title", this.getTitle());
		appendItemToToString(stringBuilder, "text", this.getText());
		appendItemToToString(stringBuilder, "postDateTime", this.getPostDateTime());
		
		return stringBuilder;
	}
}
