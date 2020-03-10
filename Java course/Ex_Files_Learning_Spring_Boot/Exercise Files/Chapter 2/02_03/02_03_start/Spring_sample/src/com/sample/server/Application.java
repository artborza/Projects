package com.sample.server;

import com.sample.service.CustomerService;
import com.sample.service.CustomerServiceImpl;

public class Application {
    public static void main(String[] args) {
        CustomerService service = new CustomerServiceImpl();
        System.out.println(service.findAll().get(0).getFirstName());
    }
}
