package com.sample.repository;

import java.util.ArrayList;
import java.util.List;
import com.sample.model.Customer;

public class HibernateCustomerRepositoryImpl implements CustomerRepository {
    public List<Customer>findAll(){
        List<Customer> customers = new ArrayList<Customer>();
        Customer customer = new Customer();
        customer.setFirstName("Phai");
        customer.setLastName("ProSbeginner");
        customers.add(customer);
        return customers;

    }
}
