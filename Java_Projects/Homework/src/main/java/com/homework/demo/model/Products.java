package com.homework.demo.model;

import org.hibernate.annotations.GenericGenerator;

import javax.persistence.*;

@Entity
public class Products {

    @Id @GeneratedValue(generator="system-uuid")
    @GenericGenerator(name="system-uuid", strategy = "uuid")
    private String Id;
    private String Name;
    private Double Price;
    private String Picture;
    private String Type;

    public String getType() {
        return Type;
    }

    public void setType(String type) {
        Type = type;
    }

    public String getPicture() {
        return Picture;
    }

    public void setPicture(String picture) {
        Picture = picture;
    }



    public String getId() {
        return Id;
    }

    public void setId(String id) {
        Id = id;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public Double getPrice() {
        return Price;
    }

    public void setPrice(Double price) {
        Price = price;
    }

    public Integer getNumber() {
        return Number;
    }

    public void setNumber(Integer number) {
        Number = number;
    }

    private Integer Number;


}
