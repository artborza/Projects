<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Buy Products</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
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
<body>
<div class="header">
    <h2 align = 'center'>  Buy Product </h2>
</div><br><br>
<form align = 'center' action="/products/buy" method="post">
    <input type="hidden" name="id"
           value="${product.id}">
    Name : ${product.name}<br><br>
    Price:${product.price}<br><br>
    Number:<input type="text" name="number" value="${product.number}"><br><br>
    <button class="btn success">Buy</button>
</form>
</body>
</html>