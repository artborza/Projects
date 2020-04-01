package com.sample.repository;

import java.util.List;
import com.sample.model.Customer;

public interface CustomerRepository {
    List<Customer>findAll();
}
