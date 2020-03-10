<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <style>

        .header {
            padding: 50px;
            text-align: center;
            background: #75b0cc;
            color: white;
        }
        .btn {
            border: none;
            color: white;
            padding: 14px 28px;
            font-size: 16px;
            cursor: pointer;
        }

        .success {background-color: #4CAF50;} /* Green */
        .success:hover {background-color: #46a049;}

    </style>
</head>
<body align = 'center'>
<div class="header">
    <h2 align = 'center'>  Detail Product </h2>
</div>
<h1>${product.name}</h1>
    Price : ${product.price}<br><br>
<form  action="/products" method="get" >
    <button class="btn success">Back</button>
</body>
</html>