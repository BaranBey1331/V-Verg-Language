clear_screen()
print "=== V-ENGINE DEGISKEN HAFIZA TESTI ==="

var input_tensor = 0
var weight_tensor = 1
var output_tensor = 2

var row_size = 3
var col_size = 4

print "Degiskenler RAM'e kaydedildi. AI Motoru cagiriliyor..."

vn_init_weights(input_tensor, row_size, col_size)
vn_init_weights(weight_tensor, col_size, row_size)

vn_dense_layer(input_tensor, weight_tensor, output_tensor)

print "Sonuc Tensörü:"
vn_print_tensor(output_tensor)
