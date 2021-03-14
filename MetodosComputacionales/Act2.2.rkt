#lang racket

;; A01701350 Jorge Alan Ramirez Elias
;; A01701490 Paulina Cardoso Fuentes

;; Insert
(define (insert n lst)
  (cond
    [(empty? lst) (cons n lst)]
    [(< n (car lst)) (cons n lst)]
    [else (cons (car lst) (insert n (cdr lst)))]))


;; Insertion sort
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


;; Rotate-left
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


;; GCD
(define (my_gcd a b)
  (gcd_acc a b 2))


;; Deep reverse
(define (deep-reverse lst)
  (cond
    [(list? lst) (reverse (map deep-reverse lst))]
    [else lst]))


;; Inserta el elemento antes del último elemento de la lista
(define (push-before-last lst x)
  (cond
    [(empty? (cdr lst)) (list  x (car lst))]
    [else (append (list(car lst)) (push-before-last (cdr lst) x))]))


;; Insert everywhere
(define (insert-everywhere x lst)
  (cond
    [(empty? lst) (list x)]
    [(not(list? x)) (cons (append (list x) lst) (insert-everywhere (append (list(car lst)) (list x)) (cdr lst))) ]
    [else(cons (append x lst) (insert-everywhere (push-before-last x (car lst))  (cdr lst))) ]))


;; Pack
(define (pack lst)
  (cond
    [(empty? lst) '()]
    [(eq? (car lst) (car (cdr lst))) (append (list (car lst) (pack (cdr lst))) (pack (cdr lst)))]
    [else (car lst)]))


;; Regresa una lista de todos los elementos consecutivos repetidos
(define (repeated lst)
  (cond
    [(equal? (car lst) (car (cdr lst))) ]
    []))


;; Compress
(define (compress lst)
  )