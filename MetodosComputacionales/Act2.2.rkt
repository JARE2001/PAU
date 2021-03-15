#lang racket

;; A01701350 Jorge Alan Ramirez Elias
;; A01701490 Paulina Cardoso Fuentes


;; 1. Insert
;; Toma dos entradas: un numero n y una lista lst que contiene numeros en orden ascendente.
;; Devuelve una nueva lista con los mismos elementos de lst pero con n insertado en su lugar correspondiente.
(define (insert n lst)
  (cond
    [(empty? lst) (cons n lst)]
    [(< n (car lst)) (cons n lst)]
    [else (cons (car lst) (insert n (cdr lst)))]))


;; 2. Insertion sort
;; Toma una lista desordenada de numeros como entrada y devuelve una nueva lista
;; con los mismos elementos pero en orden ascendente.
(define (insertion-sort lst)
   (cond
     [(empty? lst) '()]
     [else (insert (car lst) (insertion-sort (cdr lst)))]))


;; Last element
(define (last lst)
  (cond
    [(empty? (cdr lst)) (car lst)]
    [else (last (cdr lst))]))


;; El resto menos el last
(define (minus-last lst)
  (cond
    [(empty? (cdr lst)) '()]
    [else (append (list(car lst)) (minus-last (cdr lst)))]))


;; 3. Rotate-left
;; Toma dos entradas: un numero entero n y una lista lst. Devuelve la lista que resulta
;; de rotar lst un total de n elementos a la izquierda. Si n es negativo, rota hacia la derecha.
(define (rotate-left n lst)
  (cond
    [(empty? lst) '()]
    [(eq? n 0) lst]
    [(> n 0) (rotate-left (- n 1) (append (cdr lst) (list (car lst))))]
    [(< n 0) (rotate-left (+ n 1) (append (list (last lst)) (minus-last lst)))]))


;; Regresa el numero menor entre 2 entradas
(define (get-minor a b)
  (cond
    [(< a b) a]
    [else b]))

;; GCD con acumulador
(define (gcd_acc a b acc)
  (cond
    [(and (eq? (remainder a acc) 0) (eq? (remainder b acc) 0)) (* acc (gcd_acc (/ a acc) (/ b acc) 2))]
    [(eq? acc (get-minor a b)) 1]
    [else (gcd_acc a b (+ acc 1))]))


;; 5. GCD
;; La funcíon gcd toma dos numeros enteros positivos a y b como entrada, donde a > 0 y b > 0. Devuelve el
;; ḿaximo com ́un divisor (GCD por sus siglas en ingĺes) de a y b.
(define (my_gcd a b)
  (gcd_acc a b 2))


;; 6. Deep reverse
;; toma una lista como entrada. Devuelve una lista con los mismos elementos que su
;; entrada pero en orden inverso. Si hay listas anidadas, estas tambien deben invertirse.
(define (deep-reverse lst)
  (cond
    [(list? lst) (reverse (map deep-reverse lst))]
    [else lst]))


;; Inserta el elemento antes del último elemento de la lista
(define (push-before-last lst x)
  (cond
    [(empty? (cdr lst)) (list  x (car lst))]
    [else (append (list(car lst)) (push-before-last (cdr lst) x))]))


;; 7. Insert everywhere
;; Ttoma dos entradas: un objeto x y una lista lst. Devuelve una nueva lista con
;; todas las formas posibles en que se puede insertar x en cada posicion de lst
(define (insert-everywhere x lst)
  (cond
    [(empty? lst) (list x)]
    [(not(list? x)) (cons (append (list x) lst) (insert-everywhere (append (list(car lst)) (list x)) (cdr lst))) ]
    [else(cons (append x lst) (insert-everywhere (push-before-last x (car lst))  (cdr lst))) ]))


;; 9. Compress
;; Toma una lista lst como entrada. Devuelve una lista en la que los elementos repetidos
;; consecutivos de lst se reemplazan por una sola instancia. El orden de los elementos no debe modificarse.
(define (compress lst)
  (cond
    [(empty? lst)'()]
    [(empty? (cdr lst)) lst]
    [(eq? (car lst) (car (cdr lst)))(compress (cdr lst))]
    [else (append(list (car lst)) (compress (cdr lst)))]))


;; 10. Encode
;; Toma una lista lst como entrada. Los elementos consecutivos en lst se codifican en listas
;; de la forma: (n e), donde n es el n´umero de ocurrencias del elemento e
(define (encode-aux lst acc)
  (cond
    [(empty? lst)'()]
    [(empty? (cdr lst)) (list (cons acc lst))]
    [(eq? (car lst) (car (cdr lst)))(encode-aux (cdr lst) (+ 1 acc))]
    [else (cons (list acc (car lst)) (encode-aux (cdr lst) 1))]))

(define(encode lst)
  (encode-aux lst 1))


;; Decode helper
(define (decode-helper acc elem)
  (cond
    [(eq? acc 0) '()]
    [else (cons elem (decode-helper (- acc 1) elem))]))


;; 12. decode
;; Toma como entrada una lista codificada lst que tiene la misma estructura que la lista
;; resultante del problema anterior. Devuelve la version decodificada de lst.
(define (decode lst)
  (cond
    [(empty? lst) '()]
    [(list? (car lst)) (append (decode-helper (car (car lst)) (car (cdr (car lst)))) (decode (cdr lst)))]
    [else (cons (car lst) (decode (cdr lst)))]))


;; 13. Args-swap
;; Toma como entrada una funcion de dos argumentos f y devuelve una nueva funcion
;; que se comporta como f pero con el orden de sus dos argumentos intercambiados
(define (args-swap f)
  (lambda( a b)
  (f b a)))


;; 14. there-exists-one?
;; Toma dos entradas: una funci´on booleana de un argumento pred y una lista
;; lst. Devuelve verdadero si hay exactamente un elemento en lst que satisface pred, en otro caso devuelve
;; falso.
(define (there-exists-one? pred lst)
  (cond
    [(empty? lst) #f]
    [(pred (car lst)) #t]
    [else (there-exists-one? pred (cdr lst))]))


; Linear Search con acumulador
(define (linear-search-acc lst x eq-fun acc)
  (cond
    [(empty? lst) #f]
    [(eq-fun (car lst) x) acc]
    [else (linear-search-acc (cdr lst) x eq-fun (+ acc 1))]))


;; 15. Linear Search
;; Toma tres entradas: una lista lst, un valor x, y una funci´on de igualdad eq-fun.
;; Busca secuencialmente x en lst usando eq-fun para comparar x con los elementos contenidos en lst. La
;; funci´on eq-fun debe aceptar dos argumentos, a y b, y devolver verdadero si se debe considerar que a es igual
;; a b, o falso en caso contrario.
;; La funci´on linear-search devuelve el ´ındice donde se encuentra la primera ocurrencia de x en lst (el primer
;; elemento de la lista se encuentra en el ´ındice 0), o falso si no se encontr´o.

(define (linear-search lst x eq-fun)
  (linear-search-acc lst x eq-fun 0))