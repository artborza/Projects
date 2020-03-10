package com.homework.demo.model;

import org.hibernate.annotations.GenericGenerator;

import javax.persistence.*;

@Entity
public class Sale {

    @Id @GeneratedValue(generator="system-uuid")
    @GenericGenerator(name="system-uuid", strategy = "uuid")
    private String Id;
    private String Name;
    private String Number;
    private Double Price;
    private Double Total;

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public Double getTotal() {
        return Total;
    }

    public void setTotal(Double total) {
        Total = total;
    }

    public String getNumber() {
        return Number;
    }

    public void setNumber(String number) {
        Number = number;
    }


    public String getId() {
        return Id;
    }

    public void setId(String id) {
        Id = id;
    }


    public Double getPrice() {
        return Price;
    }

    public void setPrice(Double price) {
        Price = price;
    }

}
