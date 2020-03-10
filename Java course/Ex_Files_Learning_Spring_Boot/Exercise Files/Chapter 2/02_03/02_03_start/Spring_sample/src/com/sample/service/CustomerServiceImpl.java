package com.sample.service;

import java.util.List;
import com.sample.model.Customer;
import com.sample.repository.CustomerRepository;
import com.sample.repository.HibernateCustomerRepositoryImpl;

public class CustomerServiceImpl {
    private CustomerRepository customerRepository = new HibernateCustomerRepositoryImpl();
    public List<Customer> findAll() {
        return customerRepository.findAll();
    }
}
