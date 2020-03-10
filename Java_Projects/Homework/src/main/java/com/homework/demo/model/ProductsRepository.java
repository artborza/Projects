package com.homework.demo.model;

import org.springframework.stereotype.Repository;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;
import javax.transaction.Transactional;
import java.util.List;

@Repository
public class ProductsRepository {

    @PersistenceContext
    EntityManager em;

    public List findAll(){
        Query q =  em.createQuery("from Products");
        return q.getResultList();
    }

    public List findAll2(){
        Query q =  em.createQuery("from Sale");
        return q.getResultList();
    }

    public Products findByID(String Id){
        return em.find(Products.class,Id);
    }

    public Sale findByID2(String Id){
        return em.find(Sale.class,Id);
    }

    @Transactional
    public Products save(Products product){
        em.persist(product);
        return product;
    }

    @Transactional
    public Sale save2(Sale sale){
        em.persist(sale);
        return sale;
    }


    @Transactional
    public void delete(String Id){
        Products product = em.find(Products.class,Id);
        em.remove(product);
    }

    @Transactional
    public void delete2(String Id){
       Sale sale = em.find(Sale.class,Id);
        em.remove(sale);
    }




        }
