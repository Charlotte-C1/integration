/*************** Tests unitaires du module math ****************/
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "math.h"
#include <stdio.h>

/** Montage de la fixation - appelé avant chaque cas de test. **/
int init_suite(void) { return 0; }

/* Démontage de la fixation - appelé après chaque cas de test. */
int clean_suite(void) { return 0; }

/****** Cas de test - maximum avec arguments du même signe *****/
void test_maximum_meme_signe(void) {
  CU_ASSERT_EQUAL( maximum(31415, 123), 31415);
  CU_ASSERT_EQUAL( maximum(2, 1), 2);
}

/**** Cas de test - maximum avec arguments de signes opposés ***/ 
void test_maximum_signes_opposes(void) {
  CU_ASSERT_EQUAL( maximum(-21, 21), 21);
  CU_ASSERT_EQUAL( maximum(21, -21), 21);
}

/*** Cas de test - maximum avec arguments de valeurs égales ****/ 
void test_maximum_egalite(void) {
  CU_ASSERT_EQUAL( maximum(0, 0), 0);
  CU_ASSERT_EQUAL( maximum(-100, -100), -100);
  CU_ASSERT_EQUAL( maximum(1234, 1234), 1234);
}

/****** Cas de test - minimum avec arguments du même signe *****/
void test_minimum_meme_signe(void) {
  CU_ASSERT_EQUAL( minimum(31415, 123), 123);
  CU_ASSERT_EQUAL( minimum(2, 1), 1);
}

/**** Cas de test - minimum avec arguments de signes opposés ***/ 
void test_minimum_signes_opposes(void) {
  CU_ASSERT_EQUAL( minimum(-21, 21), -21);
  CU_ASSERT_EQUAL( minimum(21, -21), -21);
}

/*** Cas de test - minimum avec arguments de valeurs égales ****/ 
void test_minimum_egalite(void) {
  CU_ASSERT_EQUAL( minimum(0, 0), 0);
  CU_ASSERT_EQUAL( minimum(-100, -100), -100);
  CU_ASSERT_EQUAL( minimum(1234, 1234), 1234);
}

/****** Cas de test - addition avec arguments du même signe *****/
void test_addition_meme_signe(void) {
  CU_ASSERT_EQUAL( addition(3, 4), 7);
  CU_ASSERT_EQUAL( addition(2, 1), 3);
}

/**** Cas de test - addition avec arguments de signes opposés ***/ 
void test_addition_signes_opposes(void) {
  CU_ASSERT_EQUAL( addition(-21, 10),-11);
  CU_ASSERT_EQUAL( addition(21,-10), 11);
}


/******************* Lancement des tests ***********************/
int main ( void )
{
   CU_pSuite pSuite = NULL;
   unsigned int status = 0;

   /* initialisation des test CUnit */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* ajout de la suite de test */
   pSuite = CU_add_suite( "Test module math", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* ajout des cas de test dans la suite de test */
   if ( (NULL == CU_add_test(pSuite, "Cas de test - maximum avec arguments du même signe", test_maximum_meme_signe)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - maximum avec arguments de signes opposés", test_maximum_signes_opposes)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - maximum avec arguments égaux", test_maximum_egalite)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - minimum avec arguments du même signe", test_minimum_meme_signe)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - minimum avec arguments de signes opposés", test_minimum_signes_opposes)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - minimum avec arguments égaux", test_minimum_egalite))||
        (NULL == CU_add_test(pSuite, "Cas de test - addition avec arguments du même signe", test_addition_meme_signe)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - addition avec arguments de signes opposés", test_addition_signes_opposes)) 
        )
 
   {;
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* lancement de tous les tests avac l'interface de base */
   CU_basic_set_mode(CU_BRM_NORMAL);
   if ( CUE_SUCCESS != CU_basic_run_tests() )
      return CU_get_error();
   
   status = CU_get_number_of_tests_failed();
   CU_basic_show_failures(CU_get_failure_list());
  
   /* cloture des tests */
   CU_cleanup_registry();
   return status;
}
