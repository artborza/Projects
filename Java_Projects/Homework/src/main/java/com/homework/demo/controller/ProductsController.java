package com.homework.demo.controller;

import com.homework.demo.model.Products;
import com.homework.demo.model.ProductsRepository;
import com.homework.demo.model.Sale;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.List;


@Controller
public class ProductsController {

    @Autowired
    ProductsRepository repo;

    @GetMapping("/products")
    public String getProductList(Model model){
        List<Products> productsList = repo.findAll();
        model.addAttribute("productsList",productsList);
        List<Sale> salesList = repo.findAll2();
        model.addAttribute("salesList",salesList);
        return "list";
    }


    @GetMapping("/products/{Id}")
    public String getProduct(@PathVariable String Id,Model model)
    {
        Products product = repo.findByID(Id);
        model.addAttribute("product",product);
        return "detail";
    }


    @PostMapping("/products/create")
    public String create(@ModelAttribute Products product,Model model){
        repo.save(product);
        return "redirect:/products";
    }

    @PostMapping("/products/sale")
    public String create2(@ModelAttribute Sale sales,Model model){
        Sale sale = new Sale();
        sale.setPrice(sales.getPrice());
        sale.setNumber(sales.getNumber());
        sale.setName(sales.getName());
        sale.setTotal(((Double.valueOf(sales.getNumber())*sales.getPrice())*10000)/10000);
        repo.save2(sale);
        return "redirect:/products";
    }

    @GetMapping("/products/Delete/{Id}")
        public String delete(@PathVariable String Id){
        repo.delete(Id);
        return "redirect:/products";
        }


    @GetMapping("/products/buy/{Id}")
    public String buy(@PathVariable String Id,Model model) {
        Products product = repo.findByID(Id);
        model.addAttribute("product", product);
        return "buy-form";
    }

    @PostMapping("/products/buy")
    public String update2(@ModelAttribute Products editNumber, Model model) {
        Products product = repo.findByID(editNumber.getId());
        Integer A = product.getNumber()-editNumber.getNumber();
        if (A<=0) {
            product.setNumber(0);
        }
        else product.setNumber(A);
        repo.save(product);
        return "redirect:/products";
    }

    @GetMapping("/products/editform/{Id}")
    public String load(@PathVariable String Id,Model model) {
        Products product = repo.findByID(Id);
        model.addAttribute("product", product);
        return "/edit-form";
    }

    @PostMapping("/products/edit")
    public String update(@ModelAttribute Products editProduct, Model model) {
        Products product = repo.findByID(editProduct.getId());
        product.setNumber(editProduct.getNumber());
        product.setPrice(editProduct.getPrice());
        repo.save(product);
        return "redirect:/products";
    }


}
